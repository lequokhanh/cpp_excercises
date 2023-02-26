#include <iostream>

using namespace std;

struct NhanVien
{
    char cMaNhanVien[8];
    char cHoVaTen[20];
    char cPhongBan[10];
    int iLuongCoBan;
    int iThuong;
};

int TinhLuong (NhanVien nv) {
    return nv.iLuongCoBan + nv.iThuong;
}

int LuongThapNhat (NhanVien *nv, int n) {
    int mn = 0;
    for (int i = 0; i < n; i++) {
        mn = min (mn, nv[i].iLuongCoBan);
    }
    return mn;
}

void Nhap (NhanVien *nv, int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin.getline(nv[i].cMaNhanVien, 8);
        cin.getline(nv[i].cHoVaTen, 20);
        cin.getline(nv[i].cPhongBan, 10);
        cin >> nv[i].iLuongCoBan;
        cin >> nv[i].iThuong;
    }
}

void Xuat (NhanVien nv) {
    cout << nv.cMaNhanVien << "\t" << nv.cHoVaTen << "\t" << nv.cPhongBan << "\t" << nv.iLuongCoBan << "\t" << nv.iThuong << "\n";
}

void DSLuongThap (NhanVien *nv, int n, NhanVien *newnv, int &newsize) {
    int mn = LuongThapNhat (nv, n);
    cout << "Ma nhan vien\tHo va ten\tPhong Ban\tLuong co ban\tThuong\n";
    for (int i = 0; i < n; i++) 
        if (nv[i].iLuongCoBan == mn)
            Xuat (nv[i]);

}

void LocNVTheoLuong (NhanVien *nv, int n, NhanVien *newnv, int Luong) {
    for (int )
}
int main() {

    return 0;
}