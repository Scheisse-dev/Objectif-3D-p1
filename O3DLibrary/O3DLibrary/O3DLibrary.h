#pragma once
#ifdef O3DLIBRARY_EXPORTS
#define O3DLIBRARY_API __declspec(dllexport)
#else
#define O3DLIBRARY_API __declspec(dllimport)
#endif

extern "C" O3DLIBRARY_API void test();