#pragma once

#define MAXFIELD 9

struct CauHinh 
{
    wchar_t field[30];
    int flagTrangThai = 0;
};

void SetColor(int backgound_color, int text_color);
void ChangeFlag(int& flag);
void menu(CauHinh* cauHinh, int& flagThoat);