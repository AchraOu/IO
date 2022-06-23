#include "stdafx.h"
#include "Level.h"
#include "Cursor.h"
#include "LevelObjects.h"

extern bool g_SoloThinking;

Level::Level(int initialX, int initialY){
	m_iInitialX = initialX;
	m_iInitialY = initialY;
	m_bNeedsRepaint = false;
	m_pUpdatePacket = nullptr;
	memset(m_SolidMap, 0, sizeof(m_SolidMap));
	m_iCurObjectID = 0;
	m_iTime = 0;
	m_bSoloLevel = false;

	// The level starts out blank, so initialize everything to a single area
	memset(m_Areas, 1, sizeof(m_Areas));
}

void Level::Think(){
	if(m_Cursors.size() == 0){
		// No cursors in this level, just call CreateUpdate so it can clear
		// some vectors (added objects, removed objects, etc.)
		CreateUpdate();
		m_iLastSuccess = m_iTime;

		return;
	}

	ForceThink();
}

void Level::ForceThink(){
	OnThink();
	
	// Reset players if no one passed the level in 7 minutes
	if(m_iTime > m_iLastSuccess + 7 * 60 * 1000){
		m_iLastSuccess = m_iTime;
		ResetEveryone();
	}
	
	for(auto &c : m_Cursors){
		c->DecFloodCount();
		
		c->m_fMovementAmount *= 0.9;
	}

	auto oldObjList = m_Objects;
	for(LevelObject *obj : oldObjList){
		if(obj->Think(this)){
			// The object may have already been removed, so check it we still have it
			if(HasObject(obj) && obj->networkable){
				m_AddedObjects.push_back(obj);
			}
		}
	}

	if(m_bNeedsRepaint){
		m_bNeedsRepaint = false;
		PaintAreas();
	}

	CreateUpdate();
}

Point Level::GetUnstuckPosition(Point pos){
	if(!IsSolid(pos)) return pos;

	bool hasExplored[LEVEL_WIDTH][LEVEL_HEIGHT];
	memset(hasExplored, 0, sizeof(hasExplored));

	std::queue<Point> queue;
	queue.push(pos);
	hasExplored[pos.x][pos.y] = true;

	do {
		Point node = queue.front();
		queue.pop();
		
		if(!IsSolid(node)) return node;

		if(node.x > 0 && !hasExplored[node.x - 1][node.y]){
			queue.push(Point(node.x - 1, node.y));
			hasExplored[node.x - 1][node.y] = true;
		}

		if(node.x + 1 < Width() && !hasExplored[node.x + 1][node.y]){
			queue.push(Point(node.x + 1, node.y));
			hasExplored[node.x + 1][node.y] = true;
		}
		
		if(node.y > 0 && !hasExplored[node.x][node.y - 1]){
			queue.push(Point(node.x, node.y - 1));
			hasExplored[node.x][node.y - 1] = true;
		}

		if(node.y + 1 < Height() && !hasExplored[node.x][node.y + 1]){
			queue.push(Point(node.x, node.y + 1));
			hasExplored[node.x][node.y + 1] = true;
		}

	} while(!queue.empty());

	// Couldn't unstuck
	return pos;
}

void Level::PaintAreas(){
	memset(m_Areas, 0, sizeof(m_Areas));

	
	for(int x = 0; x < Width(); ++x){
		for(int y = 0; y < Height(); ++y){
			if(IsSolid(x, y)) m_Areas[x][y] = 1;
		}
	}

	uint numAreas = 2;

	std::vector<Point> queue;
	queue.reserve(10000);

	for(int x = 0; x < Width(); ++x){
		for(int y = 0; y < Height(); ++y){
			if(IsPainted(x, y)) continue;

			uint v = numAreas++;

			m_Areas[x][y] = v;
			queue.push_back(Point(x, y));

			do {
				Point node = queue.back();
				queue.pop_back();

				// I'm not sure if the current implementation is correct, if it's not, use this:
				if(node.x > 0 && !IsPainted(node.x - 1, node.y)){
					m_Areas[node.x - 1][node.y] = v;
					queue.push_back(Point(node.x - 1, node.y));
					
					for(int x = node.x - 2; x >= 0 && !IsPainted(x, node.y) && !IsSolid(x, node.y); --x){
						m_Areas[x][node.y] = v;
						queue.push_back(Point(x, node.y));
					}
				}

				if(node.x + 1 < Width() && !IsPainted(node.x + 1, node.y)){
					m_Areas[node.x + 1][node.y] = v;
					queue.push_back(Point(node.x + 1, node.y));
					
					for(int x = node.x + 2; x < Width() && !IsPainted(x, node.y) && !IsSolid(x, node.y); ++x){
						m_Areas[x][node.y] = v;
						queue.push_back(Point(x, node.y));
					}
				}

				if(node.y > 0 && !IsPainted(node.x, node.y - 1)){
					m_Areas[node.x][node.y - 1] = v;
					queue.push_back(Point(node.x, node.y - 1));
					
					for(int y = node.y - 2; y >= 0 && !IsPainted(node.x, y) && !IsSolid(node.x, y); --y){
						m_Areas[node.x][y] = v;
						queue.push_back(Point(node.x, y));
					}
				}

				if(node.y + 1 < Height() && !IsPainted(node.x, node.y + 1)){
					m_Areas[node.x][node.y + 1] = v;
					queue.push_back(Point(node.x, node.y + 1));
					
					for(int y = node.y + 2; y < Height() && !IsPainted(node.x, y) && !IsSolid(node.x, y); ++y){
						m_Areas[node.x][y] = v;
						queue.push_back(Point(node.x, y));
					}
				}

			} while(!queue.empty());
		}
	}

	//printf("%d areas\n", int(numAreas) - 2);

	UnstuckCursors();
}

void Level::UnstuckCursors(){
	for(Cursor *c : m_Cursors){
		if(!IsSolid(c->x, c->y)) continue;
		auto p = GetUnstuckPosition(Point(c->x, c->y));
		c->x = p.x;
		c->y = p.y;
		CreatePredictionError(c);
	}
}

Point Level::TraceLine(int x1, int y1, int x2, int y2){
	if(IsSolid(x1, y1)){
		Point p = GetUnstuckPosition(Point(x1, y1));
		p.x = x1;
		p.y = y1;
	}

	if(x1 == x2 && y1 == y2) return Point(x1, y1);
	
	int lastX = x1;
	int lastY = y1;
	
	int w = (x2 - x1);
	int h = (y2 - y1);
	int x = x1;
	int y = y1;
	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	if(w < 0) dx1 = -1; else if(w > 0) dx1 = 1;
	if(h < 0) dy1 = -1; else if(h > 0) dy1 = 1;
	if(w < 0) dx2 = -1; else if(w > 0) dx2 = 1;
	
	uint longest = abs(w);
	uint shortest = abs(h);
	if (longest <= shortest) {
		longest = abs(h);
		shortest = abs(w);
		if(h < 0) {
			dy2 = -1;
		}else if(h > 0){
			dy2 = 1;
		}
		dx2 = 0;
	}
	
	uint numerator = longest >> 1;
	for (uint i = 0; i <= longest; i++) {
		if(IsSolid(x, y)) break;
		
		lastX = x;
		lastY = y;
		
		numerator += shortest;
		if(numerator >= longest) {
			numerator -= longest;
			x += dx1;
			y += dy1;
		} else {
			x += dx2;
			y += dy2;
		}
	}
	
	return Point(lastX, lastY);
}

void Level::AddCursor(Cursor *cursor){
	if(cursor->m_pLevel != nullptr){
		cursor->m_pLevel->RemoveCursor(cursor);
	}

	cursor->m_iPassCount = 0;
	cursor->m_iLastMove = m_iTime;
	m_Cursors.push_back(cursor);
	cursor->m_pLevel = this;
	cursor->x = m_iInitialX;
	cursor->y = m_iInitialY;
	SendFullLevel(cursor);
}

void Level::RemoveCursor(Cursor *cursor){
	for(auto it = m_Cursors.begin(); it != m_Cursors.end(); ++it){
		if(*it == cursor){
			m_Cursors.erase(it);
			cursor->m_pLevel = nullptr;

			if(m_Cursors.empty()){
				for(LevelObject *obj : m_Objects){
					obj->OnEmptyLevel(this);
				}
			}

			return;
		}
	}
}

void Level::CreatePredictionError(Cursor *cursor){
	auto packet = cursor->CreatePacket(9);
	packet[0] = 0x05; // Prediction Error
	*(uint16_t*)(packet + 1) = cursor->x;
	*(uint16_t*)(packet + 3) = cursor->y;
	*(uint32_t*)(packet + 5) = ++cursor->m_iLastAck;
	cursor->SendPacket(packet);
	Cursor::DestroyPacket(packet);
}

void Level::TeleportCursor(Cursor *cursor, Level *newLevel){
	if(newLevel == this){
		cursor->x = m_iInitialX;
		cursor->y = m_iInitialY;
		CreatePredictionError(cursor);
		return;
	}

	m_iLastSuccess = m_iTime;
	ScheduledTeleport obj = { cursor, newLevel };
	m_ScheduledTeleports.push_back(obj);
}

LevelObject *Level::AddObject(LevelObject *obj){
	//printf("AddObject(%p), ref count now: %d\n", (void*) obj, obj->refCount + 1);
	if(obj->refCount++ != 0) return obj;
	
	if(obj->networkable){
		m_AddedObjects.push_back(obj);
	}

	m_Objects.push_back(obj);

	if(m_AvailableObjectIDs.empty()){
		obj->id = m_iCurObjectID++;
	}else{
		obj->id = m_AvailableObjectIDs.back();
		m_AvailableObjectIDs.pop_back();
	}

	obj->Init(this);
	return obj;
}

void Level::RemoveObject(LevelObject *obj){
	//printf("RemoveObject(%p), ref count now: %d\n", (void*) obj, obj->refCount - 1);
	if(--obj->refCount != 0) return;
	
	for(auto it = m_Objects.begin(); it != m_Objects.end(); ++it){
		if(*it == obj){
			m_Objects.erase(it);
			goto FoundObject;
		}
	}
	
	abort();
	
FoundObject:
	for(auto it = m_AddedObjects.begin(); it != m_AddedObjects.end(); ++it){
		if(*it == obj){
			m_AddedObjects.erase(it);
			break;
		}
	}

	if(obj->networkable){
		m_RemovedObjects.push_back(obj);
	}

	m_AvailableObjectIDs.push_back(obj->id);
	
	obj->Destroy(this);
}

bool Level::HasObject(LevelObject *obj){
	for(auto it = m_Objects.begin(); it != m_Objects.end(); ++it){
		if(*it == obj) return true;
	}
	return false;
}

void Level::STSolveTeleports(){
	std::vector<Cursor*> pendingDestroy;
	
	for(auto &d : m_ScheduledTeleports){
		auto cursor = d.cursor;
		auto newLevel = d.newLevel;

		if(cursor->m_pLevel != this) continue;
		RemoveCursor(cursor);
		if(newLevel != nullptr) newLevel->AddCursor(cursor);
		
		for(auto c : m_Cursors){
			if(c->m_iPassCount++ >= 500){
				pendingDestroy.push_back(c);
			}
		}
	}
	
	for(auto c : pendingDestroy){
		if(c->m_pLevel != this) continue;
		LevelManager::IncBadIP(c->m_Client.GetIP());
		c->Destroy();
	}

	m_ScheduledTeleports.clear();
}

void Level::ResetEveryone(){
	for(auto c : m_Cursors){
		c->x = m_iInitialX;
		c->y = m_iInitialY;
		c->m_iPassCount = 0;
		CreatePredictionError(c);
	}
}

void Level::CreateUpdate(){

	if(!m_Cursors.empty()){
		BinData out;
		out.PushUint8(0x01); // Update

		EncodeCursors(out);

		out.PushUint16(m_PendingClicks.size());
		for(auto &c : m_PendingClicks){
			out.PushUint16(c.x);
			out.PushUint16(c.y);
		}

		out.PushUint16(m_RemovedObjects.size());
		for(auto &obj : m_RemovedObjects){
			out.PushUint32(obj->id);
		}

		out.PushUint16(m_AddedObjects.size());
		for(auto &obj : m_AddedObjects){
			obj->Encode(out);
		}

		out.PushUint16(m_PendingLines.size());
		for(auto &l : m_PendingLines){
			out.PushUint16(l.from.x);
			out.PushUint16(l.from.y);
			out.PushUint16(l.to.x);
			out.PushUint16(l.to.y);
		}

		out.PushUint32(g_iNumCursors);

		auto packet = Cursor::CreatePacket(out.Length());
		memcpy(packet, out.Data(), out.Length());
		m_pUpdatePacket = packet;

		// We can't send it now because libuv is single threaded.
		// The packet will be sent in STSendUpdate
	}

	m_PendingClicks.clear();
	m_AddedObjects.clear();
	m_RemovedObjects.clear();
	m_PendingLines.clear();
}

void Level::STSendUpdate(){
	if(m_pUpdatePacket != nullptr){
		for(Cursor *c : m_Cursors){
			c->SendPacket(m_pUpdatePacket);
		}

		Cursor::DestroyPacket(m_pUpdatePacket);
		m_pUpdatePacket = nullptr;
	}
}

void Level::EncodeCursors(BinData &out){
	if(m_bSoloLevel){
		out.PushUint16(0);
		return;
	}

	size_t len = m_Cursors.size();
	if(len > 100) len = 100;

	out.PushUint16(len);
	for(size_t i = 0; i < len; ++i){
		Cursor *c = m_Cursors[i];
		out.PushUint32(c->id);
		out.PushUint16(c->x);
		out.PushUint16(c->y);
	}
}

void Level::SendFullLevel(Cursor *cursor){
	BinData out;
	out.PushUint8(0x04); // New Level
	out.PushUint16(cursor->x);
	out.PushUint16(cursor->y);

	size_t numNetworkable = 0;
	for(LevelObject *obj : m_Objects){
		if(obj->networkable) ++numNetworkable;
	}

	out.PushUint16(m_Objects.size());
	for(LevelObject *obj : m_Objects){
		if(!obj->networkable) continue;
		obj->Encode(out);
	}

	out.PushUint32(++cursor->m_iLastAck);

	auto packet = Cursor::CreatePacket(out.Length());
	memcpy(packet, out.Data(), out.Length());
	cursor->SendPacket(packet);
	Cursor::DestroyPacket(packet);
}

void Level::TryMoveCursor(Cursor *c, uint16_t x, uint16_t y){
	c->m_iLastMove = m_iTime;
	//if(PathExists(Point(c->x, c->y), Point(x, y))){
	//	c->x = x;
	//	c->y = y;
	//}else{
		// Prediction error, tell the client
		auto p = TraceLine(c->x, c->y, x, y);
		auto ox = c->x;
		auto oy = c->y;
		
		if(p.x != x || p.y != y){
			c->x = p.x;
			c->y = p.y;
			CreatePredictionError(c);
		}else{
			c->x = x;
			c->y = y;
		}
		
		c->m_fMovementAmount += sqrt((float) (ox - c->x) * (ox - c->x) + (float) (oy - c->y) * (oy - c->y));
		
		// Maximum I got was 3848
		//static float v;
		//v = std::max(v, c->m_fMovementAmount);
		//printf("%f\n", v);
		
		if(c->m_fMovementAmount >= 4400) c->Destroy();
	//}
}


void Level::TryClick(Cursor *c, uint16_t x, uint16_t y){
	TryMoveCursor(c, x, y);
	if(c->x != x || c->y != y) return;
	
	if(!c->TestFloodCount()) return;

	for(LevelObject *obj : m_Objects){
		obj->Click(this, c);
	}

	if(m_bSoloLevel) return;
	m_PendingClicks.push_back(Point(x, y));
}

void Level::TryDrawLine(Cursor *c, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2){
	bool valid = true;

	if(m_Cursors.size() > 30) valid = false;
	if(m_PendingLines.size() > 64) valid = false;

	if(valid){
		TryMoveCursor(c, x1, y1);
		if(c->x != x1 || c->y != y1) valid = false;
	}
	
	TryMoveCursor(c, x2, y2);
	if(c->x != x2 || c->y != y2 || !valid) return;
	
	if(m_bSoloLevel) return;
	if(!c->TestFloodCount()) return;
	
	m_PendingLines.push_back(Line(Point(x1, y1), Point(x2, y2)));
}

void Level::STKickAFK(){
	for(size_t i = 0; i < m_Cursors.size(); ++i){
		Cursor *c = m_Cursors[i];
		if(m_iTime > c->m_iLastMove + 15 * 60 * 1000){
			c->Destroy();
			--i;
		}
	}
}
