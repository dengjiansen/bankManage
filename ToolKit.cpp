#include "ToolKit.h"
#include <windows.h>
// 此处运用到WIN32API
void SetCursorPosition(const int x, const int y) {
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_BLUE |
        BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED);
}

void HideCursor(bool Visible) {
    CONSOLE_CURSOR_INFO Cursor;
    Cursor.bVisible = !Visible;
    Cursor.dwSize = sizeof(Cursor);
    HANDLE Hand = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(Hand, &Cursor);
}
