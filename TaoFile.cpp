#include <stdio.h>
#include<fcntl.h>// Để dùng hàm _setmode()
#include<io.h>// Để dùng hàm _setmode()
#include<wchar.h>
#include<stdlib.h>
#include"Menu.h"
#include"DanhSachLienKet.h"
#include"XuLyChuoi.h"

int TaoFileHTML(SinhVien* sinhVien, wchar_t* folderPath,CauHinh* cauHinh)
{
    wchar_t buffer[300];
    swprintf(buffer, 300, L"%ls\\%ls.html", folderPath, sinhVien->mssv);// lưu địa chỉ đường dẫn vào buffer

    FILE* file;
    if ((_wfopen_s(&file, buffer, L"wt")) != 0)
    {        
        wprintf(L"Tạo file html ko thành công\n");
        return 0;
    }

    _setmode(_fileno(file), _O_U8TEXT);// định dạng tập tin file mở bằng kiểu utf-8 vì .html chỉ đọc dc file ở định dạng utf-8

    fwprintf(file, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\"\n");
    fwprintf(file, L"\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
    fwprintf(file, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
    fwprintf(file, L"    <head>\n");
    fwprintf(file, L"        <meta http-equiv=\"Content - Type\" content=\"text/html; charset = utf - 8\" />\n");
    fwprintf(file, L"        <link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
    fwprintf(file, L"        <title>HCMUS - %ls</title>\n", sinhVien->hoTen);//Nguyễn Văn A - 1212123
    fwprintf(file, L"    </head>\n");
    fwprintf(file, L"    <body>\n");
    fwprintf(file, L"        <div class=\"Layout_container\">\n");
    fwprintf(file, L"            <!-- Begin Layout MainContents Region -->\n");
    fwprintf(file, L"            <div class=\"Layout_MainContents\">\n");
    fwprintf(file, L"                <!-- Begin Below Banner Region -->");
    fwprintf(file, L"                <div class=\"Personal_Main_Information\">\n");
    fwprintf(file, L"                    <div class=\"Personal_Location\">\n");
    
    wcscpy_s(buffer, sinhVien->hoTen);
    ChuyenChuThuongThanhChuHoa(buffer);
    fwprintf(file, L"                        <div class=\"Personal_FullName\">%ls - %ls</div>\n", buffer, sinhVien->mssv);//NGUYỄN VĂN A - 1212123
    wcscpy_s(buffer, sinhVien->khoa);
    ChuyenChuThuongThanhChuHoa(buffer);
    fwprintf(file, L"                        <div class=\"Personal_Department\">KHOA %ls</div>\n", buffer);//KHOA CÔNG NGHỆ THÔNG TIN
    fwprintf(file, L"                        <br />\n");
    fwprintf(file, L"                        <div class=\"Personal_Phone\">Email: %ls</div>\n",sinhVien->email);//Email: nva@gmail.com
    fwprintf(file, L"                        <br />\n");
    fwprintf(file, L"                        <br />\n");
    fwprintf(file, L"                    </div>\n");
    fwprintf(file, L"                    <div class=\"Personal_HinhcanhanKhung\">\n");
    fwprintf(file, L"                        <img src=\"Images/%ls\"\n", sinhVien->hinhAnh);// Images/1212123.jpg
    fwprintf(file, L"class=\"Personal_Hinhcanhan\" />\n");
    fwprintf(file, L"                    </div>\n");
    fwprintf(file, L"                </div>\n");
    //phần cấu hình
    fwprintf(file, L"                <!-- End Below Banner Region -->\n");
    fwprintf(file, L"                <!-- Begin MainContents Region -->\n");
    fwprintf(file, L"                <div class=\"MainContain\">\n");
    fwprintf(file, L"                    <!-- Begin Top Region -->\n");
    fwprintf(file, L"                    <div class=\"MainContain_Top\">\n");
    fwprintf(file, L"                        <div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
    fwprintf(file, L"                        <div>\n");
    fwprintf(file, L"                            <ul class=\"TextInList\">\n");

    // khi có thêm trường thì phải thay đổi MAXFIELD, thêm cấu hình trong hàm TaoFileHTML
    //0: MSSV
    //1: Họ tên
    //2: Khoa
    //3: Ngày sinh
    //4: Email
    //5: Sở thích 1
    //6: Sở thích 2
    //7: Mô tả
    //8: Tạo file HTML

    if (cauHinh[1].flagTrangThai)
    {
        fwprintf(file, L"                                <li>Họ và tên: %ls</li>\n", sinhVien->hoTen);//Nguyễn Văn A
    }
    if (cauHinh[0].flagTrangThai)
    {
        fwprintf(file, L"                                <li>MSSV: %ls</li>\n", sinhVien->mssv);//1212123
    }
    if (cauHinh[2].flagTrangThai)
    {
        fwprintf(file, L"                                <li>Sinh viên khoa %ls</li>\n", sinhVien->khoa);//Công nghệ thông tin
    }
    if (cauHinh[3].flagTrangThai)
    {
        fwprintf(file, L"                                <li>Ngày sinh: %ls</li>\n", sinhVien->ngaySinh);//20/01/1994
    }
    if (cauHinh[4].flagTrangThai)
    {
        fwprintf(file, L"                                <li>Email: %ls</li>\n",sinhVien->email);//nva@gmail.com
    }
    fwprintf(file, L"                            </ul>\n");
    fwprintf(file, L"                        </div>\n");
    fwprintf(file, L"                        <div class=\"InfoGroup\">Sở thích</div>\n");
    fwprintf(file, L"                        <div>\n");
    fwprintf(file, L"                            <ul class=\"TextInList\">\n");

    if (cauHinh[5].flagTrangThai)
    {
        fwprintf(file, L"                                <li>%ls</li>\n", sinhVien->soThich1);//Âm nhạc: POP, Balad
    }
    if (cauHinh[6].flagTrangThai)
    {
        fwprintf(file, L"                                <li>%ls</li>\n", sinhVien->soThich2);//Ẩm thực: bún riêu, bún thịt nướng
    }
    fwprintf(file, L"                            </ul>\n");
    fwprintf(file, L"                        </div>\n");
    fwprintf(file, L"                        <div class=\"InfoGroup\">Mô tả</div>\n");
    fwprintf(file, L"                        <div class=\"Description\">\n");

    if (cauHinh[7].flagTrangThai)
    {
        fwprintf(file, L"                            %ls.\n", sinhVien->moTaBanThan);//Tôi là một người rất thân thiện
    }
    fwprintf(file, L"                        </div>\n");
    fwprintf(file, L"                    </div>\n");
    fwprintf(file, L"                </div>\n");
    fwprintf(file, L"            </div>\n");
    fwprintf(file, L"            <!-- Begin Layout Footer -->\n");
    fwprintf(file, L"            <div class=\"Layout_Footer\">\n");
    fwprintf(file, L"                <div class=\"divCopyright\">\n");
    fwprintf(file, L"                    <br />\n");
    fwprintf(file, L"                                        <br />\n");
    fwprintf(file, L"                    @2024</br>\n");
    fwprintf(file, L"                    Đồ án giữ kỳ</br>\n");
    fwprintf(file, L"                Kỹ thuật lập trình</br>\n");
    fwprintf(file, L"                TH2024</br>\n");
    fwprintf(file, L"                23880224 - Trần Hoàng Hà</br>\n");
    fwprintf(file, L"                </div>\n");
    fwprintf(file, L"            </div>\n");
    fwprintf(file, L"            <!-- End Layout Footer -->\n");
    fwprintf(file, L"        </div>\n");
    fwprintf(file, L"    </body>\n");
    fwprintf(file, L"</html>\n");

    fclose(file);
    return 1;
}

void TaoFileCSS(wchar_t* folderPath)
{

    wchar_t buffer[300];
    swprintf(buffer, 300, L"%ls\\personal.css", folderPath);

    FILE* file;
    if (_wfopen_s(&file, buffer, L"wt") != 0)
    {
        wprintf(L"Tạo file css không thành công\n");
        return;
    }

    _setmode(_fileno(file), _O_U8TEXT);// định dạng tập tin file mở bằng kiểu utf-8 vì .html chỉ đọc dc file ở định dạng utf-8

    fwprintf(file, L"%ls", L"@charset \"utf - 8\"; /* CSS Document */ * { padding: 0; margin: 0; } .DivClear { clear: both; padding-top: 3px; padding-bottom: 3px; } .DivClearNone { clear: both; padding-top: 0px; padding-bottom: 0px; } html, body { margin: 0px; padding: 0px; height: 100%; } .Layout_container { width: 995px; min-height: 100%; height: auto !important; height: 100%; margin: 0 auto -147px; background-color: #D7FFF5; } .Layout_Banner { width: 100%; height: 121px; margin: 0px; background-image: url(Images/BG_banner.jpg); background-repeat:no-repeat; background-color: #D7FFF5; } .Layout_MainContents { width:100%; } .Layout_Push, .Layout_Footer { width: 100%; height: 50px; width: 995px; margin: 0 auto; } /*------------------------------*/ A { COLOR: #565656;TEXT-DECORATION: none } A:active { COLOR: #565656;TEXT-DECORATION: none } A:hover { COLOR: #ff9900; TEXT-DECORATION: none } A:visited { } .TopControl{ float:right; padding-top: 16px; padding-right: 30px; padding-bottom: 16px; text-align: right; } .Textbox{ border-top-width: 1px; border-right-width: 1px; border-bottom-width: 1px; border-left-width: 1px; border-top-style: solid; border-right-style: solid; border-bottom-style: solid; border-left-style: solid; background-color: #e4ebea; } .LoginText{ font-family: Arial, Helvetica, sans-serif; font-size: 10.5pt; font-weight: bold; text-transform: uppercase; color: #0c2a6d; } .TopControlText{ font-size: 10pt; color: #000; letter-spacing: 0.05em; font-family: Arial, Helvetica, sans-serif; line-height: 8px; margin-bottom: 10px; } .PersonalAddress{ height:237px; width: 100%; background-color: #D7FFF5; } .Personal_RightBG{ height:237px; width:163px; background-image: url(Images/BG_PersonalRight.gif); background-repeat: no-repeat; float:right; } .Personal_HinhcanhanKhung{ height: 237px; width: 190px; text-align: center; vertical-align: middle; float:right; } .Personal_Hinhcanhan{ height: 237px; width: 190px; } .Personal_Location { width: 626px; height: 207px; /*237-44*/ float: left; font-family: Arial, Helvetica, sans-serif; color: #403b33; text-align: center; padding-top: 30px; } .Personal_FullName { font-size: 15pt; font-weight: bold; padding-left: 10px; padding-bottom: 5px; letter-spacing: 80%; } .Personal_Position { font-size: 12pt; font-family: Calibri,Arial, Helvetica, sans-serif; letter-spacing: 0.0em; } .Personal_Phone { font-size: 10pt; font-family: Calibri,Arial, Helvetica, sans-serif; letter-spacing: 0.0em; } .Personal_Website{ font-family: Calibri,Arial, Helvetica, sans-serif; font-size: 12px; color: #565656; } /*------------------------------*/ .MainContain{ clear:both; width: 100%; width: 995px; background-attachment: fixed; background-image: url(Images/BG_main.gif); background-repeat: repeat-x; background-color: #FFF; background-position: right top; } .MainContain_Top{ width:100%; } .MainContain_RightTop{ float:right; width:368px; height:200px; } .MainContain_ButtonSpace{ clear:both; height:45px; width:100%; text-align: left; vertical-align: middle; font-family: Calibri,Arial, Helvetica, sans-serif; font-size: 12px; text-transform: uppercase; color: #000; font-weight: bold; letter-spacing: 0.05em; } .Button_Toolbar{ float:left; width:35px; height:36px; } .Button_Title{ float:left; text-align:left; vertical-align:middle; padding-top: 10px; padding-left: 5px; } .MainContain_LeftTop{ float:left; padding-left: 80px; width:520px; } .MainContain_Center{ clear:both; padding-left: 80px; } .InfoGroup{ text-transform: uppercase; color: #d7783c; font-family: Calibri,Arial, Helvetica, sans-serif; font-size: 13px; padding-top: 25px; font-weight: bold; padding-bottom: 10px; } .InfoSubGroup{ color: #558ED5; font-family: Calibri,Arial, Helvetica, sans-serif; font-size: 12px; padding-top: 10px; font-weight: bold; padding-bottom: 10px; } .TextInList{ font-family: Calibri,Arial, Helvetica, sans-serif; font-size: 12px; text-align: justify; color: #000000; } li{ margin-bottom: 5px; } ol li{ font-family: Calibri,Arial, Helvetica, sans-serif; font-size: 13px; font-style: italic; color: #565656; font-weight: bold; } .Paper{ font-family: Calibri,Arial, Helvetica, sans-serif; color: #565656; font-size: 11px; margin-bottom: 10px; } .PaperName{ font-weight: bold; } .PaperAuthors{ } .PaperOthers{ } /*-----------copy right---------------*/ .divCopyright{ height:147px; font-size:11px; color: #8c8c8c; text-align: center; padding-right: 10px; background-color: #D7FFF5; letter-spacing: 0.1em; } a.link:active, a.link:visited, a.link:link { text-decoration: none; } a.link:hover { text-decoration: none; color: #FF6600; } a.linkIcon:active, a.linkIcon:visited, a.linkIcon:link { text-decoration: none; color: #000; } a.linkIcon:hover { text-decoration: none; color: #FF6600; }");

    fclose(file);
}

int DocFileCSV(wchar_t* fileName, LinkList& sinhVienList)
{
    FILE* file;
    _wfopen_s(&file, fileName, L"rt");

    if (file == NULL)
    {
        wprintf(L"Không thể mở file %ls\n", fileName);
        return -1;
    }
    _setmode(_fileno(file), _O_U8TEXT);// định dạng tập tin file mở bằng kiểu unicode vì file CSV định dạng theo utf-8

    //fgetwc(file);// BOM sẽ được đọc đầu file (Byte Order Mark)

    int count = 0;
    wchar_t line[1024];

    while (fgetws(line, 1024, file) != NULL)
    {
        //wprintf(L"%ls", line);
        int i = 0;
        wchar_t mssv[11], hoTen[31], khoa[31], ngaySinh[11], email[100], hinhAnh[100], moTaBanThan[1001], soThich1[100], soThich2[100];
        TachTruong(mssv, line, i);
        TachTruong(hoTen, line, i);
        TachTruong(khoa, line, i);
        wchar_t khoaTuyenStr[5];
        TachTruong(khoaTuyenStr, line, i);
        int khoaTuyen = _wtoi(khoaTuyenStr); // Chuyển đổi chuỗi thành số nguyên
        TachTruong(ngaySinh, line, i);
        TachTruong(email, line, i);
        TachTruong(hinhAnh, line, i);
        TachTruong(moTaBanThan, line, i);
        TachTruong(soThich1, line, i);
        TachTruong(soThich2, line, i);

        SinhVien* sv = TaoSinhVien(mssv, hoTen, khoa, khoaTuyen, ngaySinh, email, hinhAnh, moTaBanThan, soThich1, soThich2);
        ThemCuoiDanhSach(sinhVienList, sv);
        count++;
    }

    fclose(file);
    return count;
}

//copy hình ảnh từ file thư mục ( chứa hình ảnh vào trong thư mục chứa trang web sinh viên
void CopyFileHinhAnh(SinhVien* sinhvien, wchar_t* folderPath)
{
    wchar_t buffer[1024];
    FILE* fileSource;
    FILE* fileDest;

    //đọc file hình ảnh của sinh viên trong thư mục Images của chương trình ở dạng nhị phân
    swprintf(buffer, 300, L"Images\\%ls.jpg", sinhvien->mssv);
    _wfopen_s(&fileSource, buffer, L"rb");
    if (fileSource == NULL)
    {
        wprintf(L"File hình ảnh hoặc thư mục %ls không tồn tại\n", buffer);
        return;
    }

    //tạo file hình ảnh của sinh viên trong "đường dẫn chứa trang web"/Images/mssv.jpg
    swprintf(buffer, 300, L"%ls\\Images\\%ls.jpg", folderPath, sinhvien->mssv);
    _wfopen_s(&fileDest, buffer, L"wb");
    if (fileDest == NULL)
    {
        wprintf(L"Không thể tạo hình ảnh tại thư mục %ls\n", buffer);
        return;
    }

    char a[1024];
    while (fread(a, sizeof(char), 1024, fileSource) > 0) {
        fwrite(&a, sizeof(char), 1024, fileDest);
    }

    fclose(fileSource);
    fclose(fileDest);
}