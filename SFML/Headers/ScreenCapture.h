#pragma once
#include <Windows.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)

using namespace std;

struct ScreenShot {
    int width;
    int height;
    int deltaX;
    int deltaY;
    string img_path;



    ScreenShot(int w, int h, int x, int y, string img_path);
};


LPWSTR CH2LPWSTR(const char* ch);

inline int GetFilePointer(HANDLE FileHandle);

bool SaveBMPFile(char* filename, HBITMAP bitmap,
    HDC bitmapDC, int width, int height);

bool ScreenCapture(int x, int y, int width, int height,
    char* filename, HWND hwnd);

