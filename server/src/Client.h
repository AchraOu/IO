#ifndef CURSORS_CLIENT_H
#define CURSORS_CLIENT_H

class Cursor;
class LevelManager;
class Client {
public:
	
	
	inline const std::string& GetIP() const { return m_IP; }
	
private:

	Client(Cursor *cursor);
	~Client();
	
	void SendPacket(char *packet);
	static char *CreatePacket(uint64_t len, uint8_t opcode = 2);
	
	// Doesn't actually destroy it, only when it's sent. Call it immediatelly after CreatePacket
	static void DestroyPacket(char *packet);
	
	
	struct DataFrame {
		uint8_t opcode;
		char  *data;
		uint64_t len;
	};

	void OnSocketData(char *data, size_t len);
	void SendRawAndDestroy(const char *data, size_t len);
	void SendRaw(const char *data, size_t len, bool ownsPointer = false);
	void ProcessDataFrame(uint8_t opcode, const char *data, size_t len);
	void CheckQueuedPackets();

	uv_tcp_t m_Socket;
	Cursor *m_pCursor;
	bool m_bClosing;
	bool m_bHasCompletedHandshake;
	std::vector<DataFrame> m_Frames;
	std::vector<char*> m_QueuedPackets;
	std::string m_IP;
	size_t m_iBufferPos;
	char m_Buffer[16 * 1024];

	friend Cursor;
	friend LevelManager;
};

extern uint32_t g_iNumCursors;

#endif
