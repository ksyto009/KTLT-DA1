#include <stdio.h>
#include<fcntl.h>// Để dùng hàm _setmode()
#include<io.h>// Để dùng hàm _setmode()
#include<wchar.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include"Menu.h"



void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void ChangeFlag(int& flag)
{
    if (flag == 0) flag = 1;
    else flag = 0;
}

void menu(CauHinh* cauHinh, int& flagThoat)
{
    int trangThai = 0;
    while (true)
    {
        system("cls");        
        wprintf(L"Chọn các trường để thể hiện thông tin trong profile page\n");
        wprintf(L"Nhấn phím mũi tên lên xuống để chọn các trường, sau đó nhấn enter để chọn trường muốn cấu hình\n");
        for (int i = 0; i < MAXFIELD; i++)
        {
            if (i == 0)
            {
                wprintf(L"┌──────────────────────────────────┐\n");
            }
            else
            {
                wprintf(L"├──────────────────────────────────┤\n");
            }
            wprintf(L"│");
            if (trangThai == i)
            {
                if (cauHinh[i].flagTrangThai == 1)
                {
                    SetColor(8, 1);
                    wprintf(L"[+] %-27ls <<", cauHinh[i].field);
                }
                else
                {
                    SetColor(8, 4);
                    wprintf(L"[-] %-27ls <<", cauHinh[i].field);
                }
            }
            else
            {
                if (cauHinh[i].flagTrangThai == 1)
                {
                    SetColor(0, 1);
                    wprintf(L"[+] %-30ls", cauHinh[i].field);
                }
                else
                {
                    wprintf(L"[-] %-30ls", cauHinh[i].field);
                }
            }
            SetColor(0, 7);
            wprintf(L"│\n");
        }
        wprintf(L"└──────────────────────────────────┘\n");

        _setmode(_fileno(stdout), _O_TEXT);

        int key = _getch();

        _setmode(_fileno(stdout), _O_U16TEXT);
        if (key == 224)// khi nhấn các phím mũi sẽ có 2 trạng thái, 224 là phím bị lún xuống, 72,80 là phím nảy lên
        {
            _setmode(_fileno(stdout), _O_TEXT);
            key = _getch();
            _setmode(_fileno(stdout), _O_U16TEXT);
            if (key == 72)
            {
                if (trangThai > 0)
                {
                    trangThai--;
                }
                else
                {
                    trangThai = MAXFIELD - 1;
                }
            }
            else if (key == 80)
            {
                if (trangThai < MAXFIELD - 1)
                {
                    trangThai++;
                }
                else
                {
                    trangThai = 0;
                }
            }
        }
        else if (key == 13)//phím enter
        {
            if (trangThai == MAXFIELD - 1)
            {
                flagThoat = 0;
                return;
            }
            for (int i = 0; i < MAXFIELD; i++)
            {
                if (trangThai == i)
                {
                    ChangeFlag(cauHinh[i].flagTrangThai);
                }
            }
        }        
    }
}