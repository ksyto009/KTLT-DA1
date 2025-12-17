#pragma once
int TaoFileHTML(SinhVien* sinhVien, wchar_t* folderPath, CauHinh* cauHinh);
void TaoFileCSS(wchar_t* folderPath);
int DocFileCSV(wchar_t* fileName, LinkList& sinhVienList);
void CopyFileHinhAnh(SinhVien* sinhvien, wchar_t* folderPath);
