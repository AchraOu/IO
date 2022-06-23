#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstdint>
#include <atomic>
#include <thread>
#include <new>
#include <chrono>
#include <memory>
#include <bitset>
#include <random>
#include <string.h>
#include <assert.h>
#include <algorithm>

#pragma warning(disable:4267)

#ifdef _WIN32
	#undef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN 1
	#include <Windows.h>
#else
	#include <unistd.h>
#endif	

#include "uv.h"

typedef unsigned int uint;
