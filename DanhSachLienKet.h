#pragma once
struct SinhVien
{
    wchar_t mssv[11];
    wchar_t hoTen[31];
    wchar_t khoa[31];
    int khoaTuyen;
    wchar_t ngaySinh[11];
    wchar_t email[100];
    wchar_t hinhAnh[100];
    wchar_t moTaBanThan[1000];
    wchar_t soThich1[100];
    wchar_t soThich2[100];
    SinhVien* pNext;
};

struct LinkList
{
    SinhVien* pHead;
    SinhVien* pTail;
};

void KhoiTao(LinkList& list);
SinhVien* TaoSinhVien(wchar_t* mssv, wchar_t* hoTen, wchar_t* khoa, int khoaTuyen, wchar_t* ngaySinh, wchar_t* email,
    wchar_t* hinhAnh, wchar_t* moTaBanThan, wchar_t* soThich1, wchar_t* soThich2);
void ThemCuoiDanhSach(LinkList& list, SinhVien* sinhVien);
void XoaDauDanhSach(LinkList& list);