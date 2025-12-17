#include<wchar.h>
#include"XuLyChuoi.h"

void TachTruong(wchar_t a[], wchar_t s[], int& i)
{
    int j = 0;
    int length = wcslen(s);
    int benTrongNgoac = 0;
    while (i < length && (s[i] != ',' || benTrongNgoac) && s[i] != '\n') //s[i] phải khác ',' hoặc benTrongNgoac true thì mới thực hiện vòng lặp
    {
        if (s[i] == '\"') //xử lý khi gặp dấu ngoặc nếu đang ở bên trong ngoặc kép thì chuyển trạng thái false ngược lại thì chuyển trạng thái true 
        {
            if (benTrongNgoac)
            {
                if (s[i + 1] == '\"')
                {
                    a[j++] = s[i++];
                }
                else
                {
                    benTrongNgoac = 0;
                }
            }
            else
            {
                benTrongNgoac = 1;
            }
            i++; // Bỏ qua dấu ngoặc kép
        }
        else
        {
            if (s[i] == ' '&& benTrongNgoac==0)
            {
                i++;
            }
            else
            {
                a[j++] = s[i++]; // Gán ký tự từ s[i] sang a[j]
            }
        }
    }
    a[j] = '\0'; // Kết thúc chuỗi a bằng ký tự '\0'

    // Nếu gặp dấu phẩy thì bỏ qua dấu phẩy
    if (s[i] == ',' && benTrongNgoac == 0)
    {
        i++;
    }
}

void ChuyenChuThuongThanhChuHoa(wchar_t* s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = ChuyenChuCaiThuongThanhChuCaiHoa(s[i]);
    }
}

wchar_t ChuyenChuCaiThuongThanhChuCaiHoa(wchar_t ch)
{
    if (ch >= L'a' && ch <= L'z') return  ch - (L'a' - L'A');
    else
    {
        switch (ch)
        {
        case L'à': return L'À';
        case L'á': return L'Á';
        case L'ả': return L'Ả';
        case L'ã': return L'Ã';
        case L'ạ': return L'Ạ';
        case L'â': return L'Â';
        case L'ầ': return L'Ầ';
        case L'ấ': return L'Ấ';
        case L'ẩ': return L'Ẩ';
        case L'ẫ': return L'Ẫ';
        case L'ậ': return L'Ậ';
        case L'ă': return L'Ă';
        case L'ằ': return L'Ằ';
        case L'ắ': return L'Ắ';
        case L'ẳ': return L'Ẳ';
        case L'ẵ': return L'Ẵ';
        case L'ặ': return L'Ặ';
        case L'è': return L'È';
        case L'é': return L'É';
        case L'ẻ': return L'Ẻ';
        case L'ẽ': return L'Ẽ';
        case L'ẹ': return L'Ẹ';
        case L'ê': return L'Ê';
        case L'ề': return L'Ề';
        case L'ế': return L'Ế';
        case L'ể': return L'Ể';
        case L'ễ': return L'Ễ';
        case L'ệ': return L'Ệ';
        case L'ì': return L'Ì';
        case L'í': return L'Í';
        case L'ỉ': return L'Ỉ';
        case L'ĩ': return L'Ĩ';
        case L'ị': return L'Ị';
        case L'ò': return L'Ò';
        case L'ó': return L'Ó';
        case L'ỏ': return L'Ỏ';
        case L'õ': return L'Õ';
        case L'ọ': return L'Ọ';
        case L'ô': return L'Ô';
        case L'ồ': return L'Ồ';
        case L'ố': return L'Ố';
        case L'ổ': return L'Ổ';
        case L'ỗ': return L'Ỗ';
        case L'ộ': return L'Ộ';
        case L'ơ': return L'Ơ';
        case L'ờ': return L'Ờ';
        case L'ớ': return L'Ớ';
        case L'ở': return L'Ở';
        case L'ỡ': return L'Ỡ';
        case L'ợ': return L'Ợ';
        case L'ù': return L'Ù';
        case L'ú': return L'Ú';
        case L'ủ': return L'Ủ';
        case L'ũ': return L'Ũ';
        case L'ụ': return L'Ụ';
        case L'ư': return L'Ư';
        case L'ừ': return L'Ừ';
        case L'ứ': return L'Ứ';
        case L'ử': return L'Ử';
        case L'ữ': return L'Ữ';
        case L'ự': return L'Ự';
        case L'ỳ': return L'Ỳ';
        case L'ý': return L'Ý';
        case L'ỷ': return L'Ỷ';
        case L'ỹ': return L'Ỹ';
        case L'ỵ': return L'Ỵ';
        default: return ch;
        }
    }
}

