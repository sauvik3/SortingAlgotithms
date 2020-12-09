#pragma once
#include "Sorting.h"

#ifdef _WIN32
	#ifdef USE_SHARED
		#ifdef DLL_EXPORTS
			#define SORTING_API __declspec(dllexport)
		#else
			#define SORTING_API __declspec(dllimport)
		#endif
	#else
		#define SORTING_API
	#endif
#else
	#define SORTING_API
#endif