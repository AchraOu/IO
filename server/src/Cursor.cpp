#include "stdafx.h"
#include "Cursor.h"
#include "LevelManager.h"

uint32_t s_iNextCursorID = 1;
std::vector<uint32_t> s_AvailableCursorIDs;
uint32_t g_iNumCursors = 0;

Cursor::Cursor() : m_Client(this) {
	m_pLevel = nullptr;
	m_bDestroyed = false;
	m_bIsInitialized = false;
	m_iLastAck = 0;
	id = 0;

	for(size_t i = 0; i < g_Cursors.size(); ++i){
		if(g_Cursors[i] != nullptr) continue;
		g_Cursors[i] = this;
		goto HasAddedToList;
	}

	g_Cursors.push_back(this);

HasAddedToList:;

}

Cursor::~Cursor(){
	for(size_t i = 0; i < g_Cursors.size(); ++i){
		if(g_Cursors[i] != this) continue;
		g_Cursors[i] = nullptr;
		break;
	}

	if(id != 0){
		--g_iNumCursors;
		s_AvailableCursorIDs.push_back(id);
	}
}

void Cursor::Init(){
	if(m_bIsInitialized) return;
	m_bIsInitialized = false;

	++g_iNumCursors;
	if(s_AvailableCursorIDs.size() > 0){
		id = s_AvailableCursorIDs.back();
		s_AvailableCursorIDs.pop_back();
	}else{
		id = s_iNextCursorID++;
		assert(id != 0);
	}

	char *hello = CreatePacket(5);
	hello[0] = 0;
	*(uint32_t*)(hello + 1) = id;
	SendPacket(hello);
	Cursor::DestroyPacket(hello);

	LevelManager::GetInitialLevel()->AddCursor(this);
}

bool Cursor::TestFloodCount(){
	if(m_iFloodCount > 3) return false;
	++m_iFloodCount;
	return true;
}

static void CursorCloseCallback(uv_handle_t* handle){
	Cursor *cursor = (Cursor*) handle->data;
	delete cursor;
}

void Cursor::Destroy(){
	m_Client.m_bClosing = true;

	if(m_bDestroyed) return;
	m_bDestroyed = true;

	if(m_pLevel != nullptr){
		m_pLevel->RemoveCursor(this);
	}
	
	uv_close((uv_handle_t*) &m_Client.m_Socket, CursorCloseCallback);
}
