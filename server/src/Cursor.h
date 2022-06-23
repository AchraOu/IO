#ifndef CURSORS_CURSOR_H
#define CURSORS_CURSOR_H

#include "Level.h" // Point
#include "Client.h"

class Level;
class LevelManager;
class Client;
class Cursor {
public:
	uint32_t id;
	uint16_t x;
	uint16_t y;

	Cursor();
	~Cursor();

	void Init();
	void Destroy();
	
	bool TestFloodCount();
	inline void DecFloodCount(){ if(m_iFloodCount > 0) --m_iFloodCount; }
	
	void SetPosition(int x, int y){ this->x = x; this->y = y; };
	void SetPosition(const Point &p){ x = p.x; y = p.y; };
	
	void SendPacket(char *packet){ m_Client.SendPacket(packet); }
	static char *CreatePacket(size_t len) { return Client::CreatePacket(len); } 
	// Doesn't actually destroy it, only when it's sent. Call it immediatelly after CreatePacket
	static void DestroyPacket(char *packet){ Client::DestroyPacket(packet);}


private:

	Client m_Client;
	Level *m_pLevel;
	bool m_bDestroyed;
	bool m_bIsInitialized;
	uint32_t m_iLastAck;
	uint32_t m_iFloodCount = 0;
	uint64_t m_iLastMove;
	uint32_t m_iPassCount = 0;
	float m_fMovementAmount = 0;
	
	friend Level;
	friend LevelManager;
	friend Client;
};

#endif