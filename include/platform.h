#ifndef PLATFORM_H
#define PLATFORM_H

typedef struct {
    int ws_col;
    int ws_row;
} WindowSize;
WindowSize getConsoleInfo();
#ifdef _WIN32

#include<windows.h>
#define CLEAR_SCREEN() system("cls")


#else
#include<unistd.h>
#define CLEAR_SCREEN() system("clear")
#endif

#endif // PLATFORM_H