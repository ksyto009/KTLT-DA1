#include <stdio.h>
#include<fcntl.h>// Để dùng hàm _setmode()
#include<io.h>// Để dùng hàm _setmode()
#include<wchar.h>
#include<stdlib.h>
#include<Windows.h>

#include"Menu.h"
#include"DanhSachLienKet.h"
#include"TaoFile.h"
#include"XuLyChuoi.h"

int main(void)
{
    int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);//set output thành chữ unicode
    _setmode(_fileno(stdin), _O_U16TEXT);//set input thành chữ unicode

    wchar_t folderPath[300];
    wchar_t fileName[300];

    wprintf(L"Nhập đường dẫn thư mục chứa các file html VD (C:\\Desktop\\Folder Path): ");
    _getws_s(folderPath,300);

    wchar_t buffer[300];
    //kiểm tra xem thư mục có tồn tại không
    swprintf(buffer, 300,L"%ls\\kiemtratontaithumuc.txt", folderPath);
    FILE* file;
    if ((_wfopen_s(&file, buffer, L"wt")) != 0)
    {
        wprintf(L"Không tồn tại thư mục %ls\n", folderPath);
        return 0;
    }
    else
    {
        //đóng file đã mở sau đó xóa file kiemTratontaithumuc.txt
        fclose(file);
        _wremove(buffer);
    }

    wprintf(L"Nhập đường dẫn file csv VD (C:\\Desktop\\File Name): ");
    _getws_s(fileName);

    LinkList sinhVienList;
    KhoiTao(sinhVienList);

    int count = DocFileCSV(fileName, sinhVienList);  

    if (count == -1) return 0;

    // khi có thêm trường thì phải thay đổi MAXFIELD, thêm cấu hình trong hàm TaoFileHTML, DocFileCSV
    //0: MSSV
    //1: Họ tên
    //2: Khoa
    //3: Ngày sinh
    //4: Email
    //5: Sở thích 1
    //6: Sở thích 2
    //7: Mô tả
    //8: Tạo file HTML
    CauHinh cauHinh[MAXFIELD] = {
        {L"MSSV"},
        {L"Họ tên"},
        {L"Khoa"},
        {L"Ngày sinh"},
        {L"Email"},
        {L"Sở thích 1"},
        {L"Sở thích 2"},
        {L"Mô tả"},
        {L"Tạo file HTML"}
    };

    int flagThoat = 1;
    while (flagThoat)
    {
        menu(cauHinh, flagThoat);
    }


    //tạo thư mục Images
    swprintf(buffer, 300, L"%ls\\Images", folderPath);
    if (CreateDirectoryW(buffer, NULL))
    {
        wprintf(L"Thư mục %ls đã được tạo thành công\n", buffer);
    }
    else
    {
        wprintf(L"Đã tồn tại thư mục %ls\n", buffer);
    }

    int flagHTML = 1;
    SinhVien* node = sinhVienList.pHead;
    while (node != NULL)
    {
        flagHTML = TaoFileHTML(node, folderPath, cauHinh);

        CopyFileHinhAnh(node,folderPath);
        
        node = node->pNext;

    }

    TaoFileCSS(folderPath);





    


    

    wprintf(L"Tạo file thành công và chứa trong thư mục %ls\n", folderPath);

    while (sinhVienList.pHead != NULL)
    {
        XoaDauDanhSach(sinhVienList);
    }

    return 1;
}