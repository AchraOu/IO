#include "stdafx.h"
#include "LevelManager.h"
#include "Cursor.h"

#include <unordered_map>

#include "levels/000x.h"
#include "levels/001x.h"
#include "levels/002x.h"
#include "levels/003x.h"
#include "levels/004x.h"
#include "levels/005x.h"
#include "levels/006x.h"

static uint s_iNumThreads = 0;

uv_loop_t g_Loop;
uv_tcp_t g_Server;

// Level loading
#define MAX_LEVELS 1024
Level *s_Levels[MAX_LEVELS];
size_t s_iNumLevels = 0;

LevelManager::LevelWorker *s_Workers;

std::atomic<bool> s_Running(true);

std::vector<Cursor*> g_Cursors;
uint64_t g_iStartTime;

int s_iLastActualLevel = 0;

bool g_SoloThinking = false;

std::unordered_map<std::string, size_t> g_BadIPs;

void LevelManager::Init(){
	std::srand((unsigned int) time(NULL));
	printf("Running libuv version %s\n", uv_version_string());
	uv_set_process_title("Cursors Server -- Build: " __TIMESTAMP__);
	
#ifndef _WIN32
	signal(SIGPIPE, SIG_IGN);
#endif

	uv_loop_init(&g_Loop);

	s_iNumThreads = std::thread::hardware_concurrency();
	if(s_iNumThreads == 0) s_iNumThreads = 1;
	
	int shuffleStart;
	auto ShuffleLevels = [&](){
		#ifndef DEBUG
			std::random_shuffle(&s_Levels[shuffleStart], &s_Levels[s_iNumLevels]);
		#endif
	};


	s_Levels[s_iNumLevels++] = new EmptyLevel();
	s_Levels[s_iNumLevels++] = new Level0001();
	s_Levels[s_iNumLevels++] = new Level0006();
	s_Levels[s_iNumLevels++] = new Level0007();

	shuffleStart = s_iNumLevels;
	s_Levels[s_iNumLevels++] = new Level0008();
	s_Levels[s_iNumLevels++] = new Level0009();
	s_Levels[s_iNumLevels++] = new Level0002();
	s_Levels[s_iNumLevels++] = new Level0003();
	//s_Levels[s_iNumLevels++] = new Level0004();
	s_Levels[s_iNumLevels++] = new Level0005();
	s_Levels[s_iNumLevels++] = new Level0010();
	s_Levels[s_iNumLevels++] = new Level0011();
	ShuffleLevels();

	int iteration = 0;
	while(s_iNumLevels < 500){
		printf("Setting up cycle %d\n", iteration + 1);
		shuffleStart = s_iNumLevels;
		s_Levels[s_iNumLevels++] = new Level0012();
		s_Levels[s_iNumLevels++] = new Level0013();
		s_Levels[s_iNumLevels++] = new Level0014();
		s_Levels[s_iNumLevels++] = new Level0015();
		s_Levels[s_iNumLevels++] = new Level0016();
		s_Levels[s_iNumLevels++] = new Level0017();
		s_Levels[s_iNumLevels++] = new Level0018();
		s_Levels[s_iNumLevels++] = new Level0019();
		s_Levels[s_iNumLevels++] = new Level0020();
		s_Levels[s_iNumLevels++] = new Level0021();
		s_Levels[s_iNumLevels++] = new Level0022();
		s_Levels[s_iNumLevels++] = new Level0023();
		s_Levels[s_iNumLevels++] = new Level0024();
		s_Levels[s_iNumLevels++] = new Level0025();
		s_Levels[s_iNumLevels++] = new Level0026();
		s_Levels[s_iNumLevels++] = new Level0027();
		s_Levels[s_iNumLevels++] = new Level0028();
		s_Levels[s_iNumLevels++] = new Level0029();
		s_Levels[s_iNumLevels++] = new Level0030();
		s_Levels[s_iNumLevels++] = new Level0031();
		s_Levels[s_iNumLevels++] = new Level0032();
		s_Levels[s_iNumLevels++] = new Level0033();
		s_Levels[s_iNumLevels++] = new Level0034();
		s_Levels[s_iNumLevels++] = new Level0035();
		s_Levels[s_iNumLevels++] = new Level0036();
		s_Levels[s_iNumLevels++] = new Level0037();
		s_Levels[s_iNumLevels++] = new Level0038();
		s_Levels[s_iNumLevels++] = new Level0039();
		s_Levels[s_iNumLevels++] = new Level0040();
		s_Levels[s_iNumLevels++] = new Level0042();
		s_Levels[s_iNumLevels++] = new Level0043();
		s_Levels[s_iNumLevels++] = new Level0044();
		s_Levels[s_iNumLevels++] = new Level0045();
		s_Levels[s_iNumLevels++] = new Level0046();
		s_Levels[s_iNumLevels++] = new Level0047();
		s_Levels[s_iNumLevels++] = new Level0048();
		s_Levels[s_iNumLevels++] = new Level0049();
		s_Levels[s_iNumLevels++] = new Level0050();
		s_Levels[s_iNumLevels++] = new Level0051();
		s_Levels[s_iNumLevels++] = new Level0052();
		s_Levels[s_iNumLevels++] = new Level0053();
		s_Levels[s_iNumLevels++] = new Level0054();
		s_Levels[s_iNumLevels++] = new Level0055();
		s_Levels[s_iNumLevels++] = new Level0056();
		s_Levels[s_iNumLevels++] = new Level0057();
		s_Levels[s_iNumLevels++] = new Level0058();
		s_Levels[s_iNumLevels++] = new Level0059();
		s_Levels[s_iNumLevels++] = new Level0060();
		s_Levels[s_iNumLevels++] = new Level0061();
		s_Levels[s_iNumLevels++] = new Level0062();
		s_Levels[s_iNumLevels++] = new Level0063();
		ShuffleLevels();
		if(iteration == 0){
			s_iLastActualLevel = s_iNumLevels - 1;
			s_Levels[s_iNumLevels++] = new Level0041();
			s_Levels[s_iNumLevels++] = new LastLevel();
		}

#ifdef DEBUG
		if(iteration == 1) break;
#endif
		++iteration;
	}

	s_Levels[s_iNumLevels++] = new EmptyLevel();

	
	puts("Initializing levels");
#ifdef DEBUG
	for(size_t i = s_iLastActualLevel; i < s_iLastActualLevel + 5; ++i){
		s_Levels[i]->Init();
	}
#else
	for(size_t i = 0; i < s_iNumLevels; ++i){
		s_Levels[i]->Init();
	}
#endif

	
	printf("Running %d worker threads\n", s_iNumThreads);
	s_Workers = (LevelWorker*) malloc(sizeof(LevelWorker) * s_iNumThreads);
	for(uint i = 0; i < s_iNumThreads; ++i){
		new (&s_Workers[i]) LevelWorker(i);
	}
	
	uv_tcp_init(&g_Loop, &g_Server);
	struct sockaddr_in addr;
	uv_ip4_addr("0.0.0.0", 2828, &addr);
	uv_tcp_nodelay(&g_Server, true);
	uv_tcp_bind(&g_Server, (const struct sockaddr*) &addr, 0);
	uv_listen((uv_stream_t*) &g_Server, 256, OnConnection);

}


void LevelManager::OnConnection(uv_stream_t* server, int status){
	if(status < 0) return;

	auto cursor = new Cursor();
	uv_tcp_t *client = &cursor->m_Client.m_Socket;
	client->data = cursor;

	uv_tcp_init(&g_Loop, client);
	if(uv_accept(server, (uv_stream_t*) client) == 0){
		struct sockaddr_storage addr;
		
		int addr_len = sizeof(addr);
		uv_tcp_getpeername(client, (struct sockaddr*) &addr, &addr_len);
		
		char buf[128];
		if(uv_ip4_name((struct sockaddr_in*) &addr, buf, sizeof buf) != 0) buf[0] = '\0';
		
		
		uv_tcp_nodelay(client, true);
		uv_read_start((uv_stream_t*) client, AllocBuffer, OnSocketData);
		
		
		if(buf[0] != '\0'){
			int count = 0;
			
			cursor->m_Client.m_IP = buf;
			for(auto c : g_Cursors){
				if(!c) continue;
				if(c == cursor) continue;
				if(c->m_Client.m_IP == buf) ++count;
			}
			
			auto it = g_BadIPs.find(cursor->m_Client.m_IP);
			
			if(count >= 3 || (it != g_BadIPs.end() && it->second >= 10)){
				cursor->Destroy();
			}
		}
	}else{
		uv_close((uv_handle_t*) client, [](uv_handle_t* handle){
			delete (Cursor*) handle->data;
		});
	}
}

void LevelManager::AllocBuffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf){
	buf->base = new char[suggested_size];
	buf->len = suggested_size;
}

void LevelManager::OnSocketData(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf){
	Cursor *cursor = (Cursor*) stream->data;
	assert(cursor != nullptr);
	if(nread < 0){
		cursor->Destroy();
		return;
	}else{
		if(nread != 0){
			cursor->m_Client.OnSocketData(buf->base, (size_t) nread);
		}
	}

	if(buf != nullptr) delete[] buf->base;
}

LevelManager::LevelWorker::LevelWorker(uint id)
	: thread(LevelManager::Worker, id)
{
	this->id = id;
	thinking.store(false);

}

void LevelManager::Worker(uint id){

	while(s_Running.load()){
		while(!s_Workers[id].thinking.load()){
			if(!s_Running.load()) return;
#ifdef DEBUG
			Sleep(1);
#else
			Sleep(0);
#endif
		}

		if(!s_Running.load()) return;

		for(size_t i = id; i < s_iNumLevels; i += s_iNumThreads){
			Level *level = s_Levels[i];
			if(level == nullptr) continue;
			level->Think();
		}

		s_Workers[id].thinking.store(false);
	}
}

// We need to sync all threads so we can communicate with libuv
void LevelManager::Run(){

	auto Now = [&]() -> uint64_t {
		if(std::chrono::high_resolution_clock::is_steady){
			auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
			return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
		}else{
			auto now = std::chrono::steady_clock::now().time_since_epoch();
			return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
		}
	};

	g_iStartTime = Now();
	
	/*
	{
		auto start = Now();

		for(int i = 0; i < 100; ++i){
			s_Levels[1]->PaintAreas();
		}

		auto end = Now();

		printf("PaintAreas %f ms\n", double(end - start) / 100);
	}
	*/

	auto HaveAllFinishedThinking = [&](){
		for(size_t i = 0; i < s_iNumThreads; ++i){
			if(s_Workers[i].thinking.load()) return false;
		}
		return true;
	};

	auto WaitForEveryone = [&](){
		while(!HaveAllFinishedThinking()) Sleep(0);
	};
	
	auto ThinkAll = [&](){
		auto curTime = Now() - g_iStartTime;

		for(size_t i = 0; i < s_iNumLevels; ++i){
			if(s_Levels[i] == nullptr) continue;
			s_Levels[i]->m_iTime = curTime;
		}

		g_SoloThinking = false;
		for(size_t i = 0; i < s_iNumThreads; ++i){
			s_Workers[i].thinking.store(true);
		}
		WaitForEveryone();

		g_SoloThinking = true;

		for(Cursor *c : g_Cursors){
			if(c == nullptr) continue;
			c->m_Client.CheckQueuedPackets();
		}

		for(size_t i = 0; i < s_iNumLevels; ++i){
			if(s_Levels[i] == nullptr) continue;
			s_Levels[i]->STSolveTeleports();
		}
		
		for(size_t i = 0; i < s_iNumLevels; ++i){
			if(s_Levels[i] == nullptr) continue;
			s_Levels[i]->STSendUpdate();
		}

		for(size_t i = 0; i < s_iNumLevels; ++i){
			if(s_Levels[i] == nullptr) continue;
			s_Levels[i]->STKickAFK();
		}
	};

	{
		double den, num;
		if(std::chrono::high_resolution_clock::is_steady){
			den = (double) std::chrono::high_resolution_clock::period::den;
			num = (double) std::chrono::high_resolution_clock::period::num;
		}else{
			den = (double) std::chrono::steady_clock::period::den;
			num = (double) std::chrono::steady_clock::period::num;
		}

		double msPrecision = (num * 1000.0 / den);
		if(msPrecision >= 0.1){
			printf("Warning! System clock too imprecise (%f ms)!\n", msPrecision);
		}
	}

	puts("All done. Running main loop");
	while(s_Running.load()){
		auto timeStart = Now();
		uv_run(&g_Loop, UV_RUN_NOWAIT);

		ThinkAll();

		auto timeEnd = Now();

		const int FRAMES_PER_SECOND = 20;
		const int SLEEP_TIME = 1000 / FRAMES_PER_SECOND;
		Sleep(SLEEP_TIME - int(timeEnd - timeStart));
	}

	for(uint i = 0; i < s_iNumThreads; ++i){
		s_Workers[i].thread.join();
	}
}

void LevelManager::Destroy(){
	uv_close((uv_handle_t*) &g_Server, nullptr);
	uv_loop_close(&g_Loop);
}

void LevelManager::Sleep(int ms){
	if(ms < 0) return;
	if(ms == 0){
		#ifndef _WIN32
			usleep(1); //sched_yield();
			return;
		#endif
	}

	#ifdef _WIN32
		::Sleep(ms);
	#else
		usleep(ms * 1000);
	#endif
}

Level *LevelManager::GetInitialLevel(){
#ifdef DEBUG
	return s_Levels[s_iLastActualLevel];
#endif
	return s_Levels[1];
}

Level *LevelManager::GetLevel(uint code){
	return s_Levels[code];
}

Level *LevelManager::GetNextLevel(Level *current){
	for(size_t i = 0; i < s_iNumLevels; ++i){
		if(current == s_Levels[i]){
			return s_Levels[i + 1];
		}
	}
	return s_Levels[0];
}

Level *LevelManager::GetPreviousLevel(Level *current){
	for(size_t i = 1; i < s_iNumLevels; ++i){
		if(current == s_Levels[i]){
			return s_Levels[i - 1];
		}
	}
	return s_Levels[0];
}

int LevelManager::GetNumDesiredInstances(){
	return g_iNumCursors / 600;
}

void LevelManager::IncBadIP(const std::string &ip){
	g_BadIPs[ip] += 1;
}
