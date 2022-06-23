#ifndef CURSORS_LEVELMANAGER_H
#define CURSORS_LEVELMANAGER_H

#include "Level.h"


extern bool g_SoloThinking;
extern std::vector<Cursor*> g_Cursors;
class LevelManager {
public:
	struct LevelWorker {
		uint id;
		std::atomic<bool> thinking;
		std::thread thread;

		LevelWorker(uint id);
	};

	static Level *GetInitialLevel();
	static Level *GetLevel(uint code);
	static Level *GetNextLevel(Level *current);
	static Level *GetPreviousLevel(Level *current);
	
	static void Worker(uint id);
	static void Sleep(int ms);

	static void Init();
	static void Run();
	static void Destroy();
	static void OnConnection(uv_stream_t* server, int status);
	static void AllocBuffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf);
	static void OnSocketData(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf);
	
	static void IncBadIP(const std::string &ip);

	static int GetNumDesiredInstances();
};

#endif