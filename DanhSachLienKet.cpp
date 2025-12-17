#include <stdio.h>
#include<wchar.h>
#include"DanhSachLienKet.h"


void KhoiTao(LinkList& list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

SinhVien* TaoSinhVien(wchar_t* mssv, wchar_t* hoTen, wchar_t* khoa, int khoaTuyen, wchar_t* ngaySinh, wchar_t* email,
    wchar_t* hinhAnh, wchar_t* moTaBanThan, wchar_t* soThich1, wchar_t* soThich2)
{
    SinhVien* sv = new SinhVien;
    wcscpy_s(sv->mssv, mssv);
    wcscpy_s(sv->hoTen, hoTen);
    wcscpy_s(sv->khoa, khoa);
    sv->khoaTuyen = khoaTuyen;
    wcscpy_s(sv->ngaySinh, ngaySinh);
    wcscpy_s(sv->email, email);
    wcscpy_s(sv->hinhAnh, hinhAnh);
    wcscpy_s(sv->moTaBanThan, moTaBanThan);
    wcscpy_s(sv->soThich1, soThich1);
    wcscpy_s(sv->soThich2, soThich2);
    sv->pNext = NULL;
    return sv;
}

void ThemCuoiDanhSach(LinkList& list, SinhVien* sinhVien)
{
    if (list.pHead == NULL)
    {
        list.pHead = sinhVien;
        list.pTail = sinhVien;
    }
    else
    {
        list.pTail->pNext = sinhVien;
        list.pTail = sinhVien;
    }
}

void XoaDauDanhSach(LinkList& list)
{
    if (list.pHead != NULL)
    {
        SinhVien* p = list.pHead;
        list.pHead = list.pHead->pNext;
        if (list.pHead == NULL)
        {
            list.pTail = NULL;
        }
        delete p;
    }
}