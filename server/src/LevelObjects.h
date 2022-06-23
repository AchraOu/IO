#ifndef CURSORS_LEVELOBJECTS_H
#define CURSORS_LEVELOBJECTS_H

#include "Level.h"
#include "BinData.h"
#include "LevelManager.h"


struct LevelObject {
	virtual ~LevelObject(){};
	virtual void Init(Level *l){}
	virtual void Destroy(Level *l){}
	// Return true if we need to send this object to the client again
	virtual bool Think(Level *l){ return false; };
	virtual void Encode(BinData &out){ out.PushUint32(id); };
	virtual void Click(Level *l, Cursor *c){}
	virtual void OnEmptyLevel(Level *l){}
	
	bool IsInLevel() const { return refCount > 0; }
	
private:
	uint32_t id;
	
	int refCount = 0;

protected:
	bool networkable = true;

	friend Level;
};

// Note: It doesn't own the pointer, so it's only really suitable for string literals
struct ObjText : public LevelObject {
	ObjText(const char *value, int x, int y, bool isCentered, int size = 20) : value(value), x(x), y(y), size(size), isCentered(isCentered) {}
	void Encode(BinData &out){
		LevelObject::Encode(out);
		out.PushUint8(0x00);
		out.PushUint16(x);
		out.PushUint16(y);
		out.PushUint8(size);
		out.PushUint8(isCentered ? 1 : 0);
		out.PushString(value);

	}

private:
	const char *value;
	int x;
	int y;
	int size;
	bool isCentered;
};

struct ObjWall : public LevelObject {
	ObjWall(int x, int y, int width, int height, uint32_t color = 0) : x(x), y(y), width(width), height(height), color(color) {

	}

	void Init(Level *l){
		l->InvalidateAreas();
		for(int px = x; px < x + width; ++px){
			if(px < 0) continue;
			if(px >= l->Width()) continue;
			for(int py = y; py < y + height; ++py){
				if(py < 0) continue;
				if(py >= l->Height()) break;
				l->IncSolid(px, py);
			}
		}
	}

	void Destroy(Level *l){
		l->InvalidateAreas();
		for(int px = x; px < x + width; ++px){
			if(px < 0) continue;
			if(px >= l->Width()) continue;
			for(int py = y; py < y + height; ++py){
				if(py < 0) continue;
				if(py >= l->Height()) break;
				l->DecSolid(px, py);
			}
		}
	}

	void Encode(BinData &out){
		LevelObject::Encode(out);
		out.PushUint8(0x01);
		out.PushUint16(x);
		out.PushUint16(y);
		out.PushUint16(width);
		out.PushUint16(height);
		out.PushUint32(color);
	}

private:
	int x;
	int y;
	int width;
	int height;
	uint32_t color;
};

struct ObjTeleport : public LevelObject {
	ObjTeleport(Level *l, int x, int y, int width, int height, bool isBad = false) : nextLevel(l), x(x), y(y), width(width), height(height), isBad(isBad) {

	}

	bool Think(Level *l){
		for(Cursor *c : l->GetCursors()){
			if(c->x < x) continue;
			if(c->y < y) continue;
			if(c->x >= x + width) continue;
			if(c->y >= y + height) continue;
			l->TeleportCursor(c, nextLevel);
		}
		return false;
	}

	void Encode(BinData &out){
		LevelObject::Encode(out);
		out.PushUint8(0x02);
		out.PushUint16(x);
		out.PushUint16(y);
		out.PushUint16(width);
		out.PushUint16(height);
		out.PushUint8(isBad);
	}

	inline void SetNextLevel(Level *l){ nextLevel = l; }

private:
	Level *nextLevel;
	int x;
	int y;
	int width;
	int height;
	bool isBad;
};

struct ObjAreaCounter : public LevelObject {
	ObjAreaCounter(LevelObject *linkedObject, int x, int y, int width, int height, int needed, uint32_t color) :
		x(x), y(y), width(width), height(height), needed(needed), color(color)
	{
		if(linkedObject != nullptr){
			linkedObjects.push_back(linkedObject);
		}
	}

	ObjAreaCounter(const std::vector<LevelObject*> &linkedObjects, int x, int y, int width, int height, int needed, uint32_t color) :
		linkedObjects(linkedObjects), x(x), y(y), width(width), height(height), needed(needed), color(color)
	{
	}
	
	void Init(Level *l){
		lastStateCanPass = false;
		
		for(auto &obj : linkedObjects){
			if(!obj->IsInLevel()) l->AddObject(obj);
		}
	}

	bool Think(Level *l){
		int count = 0;
		for(Cursor *c : l->GetCursors()){
			if(c->x < x) continue;
			if(c->y < y) continue;
			if(c->x >= x + width) continue;
			if(c->y >= y + height) continue;
			++count;
		}

		bool canPass = count >= needed;

		if(canPass != lastStateCanPass){
			if(canPass){
				for(auto &obj : linkedObjects){
					l->RemoveObject(obj);
				}
			}else{
				for(auto &obj : linkedObjects){
					l->AddObject(obj);
				}
			}
			lastStateCanPass = canPass;
		}

		if(count != lastCount){
			lastCount = count;
			return true;
		}

		return false;
	}

	void Encode(BinData &out){
		LevelObject::Encode(out);
		out.PushUint8(0x03);
		out.PushUint16(x);
		out.PushUint16(y);
		out.PushUint16(width);
		out.PushUint16(height);
		
		if(lastCount >= needed){
			out.PushUint16(0);
		}else{
			out.PushUint16(needed - lastCount);
		}
		out.PushUint32(color);
	}

	void AddLinkedObject(LevelObject *obj){ linkedObjects.push_back(obj); };

private:
	
	int x;
	int y;
	int width;
	int height;
	int needed;
	int lastCount = 0;
	uint32_t color;
	bool lastStateCanPass = false;

	std::vector<LevelObject*> linkedObjects;
};

struct ObjClickBox : public LevelObject {
	ObjClickBox(LevelObject *linkedObject, int x, int y, int width, int height, int maxCount, int regenRate, uint32_t color, int restartTime = 3500) :
		x(x), y(y), width(width), height(height), color(color), maxCount(maxCount), count(maxCount), regenRate(regenRate), restartTime(restartTime)
	{
		if(linkedObject != nullptr){
			linkedObjects.push_back(linkedObject);
		}
	}

	ObjClickBox(const std::vector<LevelObject*> &linkedObjects, int x, int y, int width, int height, int maxCount, int regenRate, uint32_t color, int restartTime = 3500) :
		linkedObjects(linkedObjects), x(x), y(y), width(width), height(height), color(color), maxCount(maxCount), count(maxCount), regenRate(regenRate), restartTime(restartTime)
	{
	}

	void Init(Level *l){
		linkedObjState = true;
		
		for(auto &obj : linkedObjects){
			if(!obj->IsInLevel()) l->AddObject(obj);
		}
	}

	void Click(Level *l, Cursor *c){
		if(c->x < x) return;
		if(c->y < y) return;
		if(c->x >= x + width) return;
		if(c->y >= y + height) return;
		

		if(count > 0){
			--count;
			hasChanged = true;
		}

		if(count == 0){
			nextRegenAt = l->GetTime() + restartTime;
		}else{
			uint64_t possibleNextRegen = l->GetTime() + regenRate + restartTime;
			if(possibleNextRegen < nextRegenAt){
				nextRegenAt = possibleNextRegen;
			}
		}
	}

	bool Think(Level *l){
		if(count < maxCount && l->GetTime() >= nextRegenAt){
			++count;
			nextRegenAt = l->GetTime() + regenRate;
			hasChanged = true;
		}

		UpdateState(l);

		if(hasChanged){
			hasChanged = false;
			return true;
		}
		return false;
	}
	
	void UpdateState(Level *l){
		bool nextLinkedObjState = count > 0;
		if(linkedObjState != nextLinkedObjState){
			linkedObjState = nextLinkedObjState;
			if(linkedObjState){
				for(auto &obj : linkedObjects){
					l->AddObject(obj);
				}
			}else{
				for(auto &obj : linkedObjects){
					l->RemoveObject(obj);
				}
			}
		}
	}

	void Encode(BinData &out){
		LevelObject::Encode(out);
		out.PushUint8(0x04);
		out.PushUint16(x);
		out.PushUint16(y);
		out.PushUint16(width);
		out.PushUint16(height);
		out.PushUint16(count);
		out.PushUint32(color);

	}

	void OnEmptyLevel(Level *l){
		if(count == maxCount) return;
		count = maxCount;
		UpdateState(l);
		hasChanged = true;
	}

	void AddLinkedObject(LevelObject *obj){ linkedObjects.push_back(obj); };

private:
	int x;
	int y;
	int width;
	int height;
	uint32_t color;
	uint16_t count;
	int maxCount;
	int regenRate;
	int restartTime;
	uint64_t nextRegenAt = 0;
	bool hasChanged = true;
	bool linkedObjState = false;


	std::vector<LevelObject*> linkedObjects;
};

#endif