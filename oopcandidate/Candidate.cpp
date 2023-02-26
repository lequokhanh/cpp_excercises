#include "Candidate.h"

using namespace std;
void Candidate::input(int iSTT) {
    this->iSTT = iSTT;
    cin >> sMa;
    cin.ignore();
    getline(cin, sHoTen);
    cin >> sNgaySinh;
    do {
        cin >> iDiemToan >> iDiemVan >> iDiemAnh;
    } while (iDiemToan < 0 || iDiemToan > 10 || iDiemVan < 0 || iDiemVan > 10 || iDiemAnh < 0 || iDiemAnh > 10);
}
int Candidate::tinhTong() {
    return iDiemToan + iDiemVan + iDiemAnh;
}
void Candidate::output() {
    cout << "-" << endl;
    cout << "STT " << iSTT << ":" << endl;
    cout << "Thong tin hoc sinh:" << endl;
    cout << "Ma: " << sMa << endl;
    cout << "Ho ten: " << sHoTen << endl;
    cout << "Ngay sinh: " << sNgaySinh << endl;
    cout << "Diem toan: " << iDiemToan << endl;
    cout << "Diem van: " << iDiemVan << endl;
    cout << "Diem anh: " << iDiemAnh << endl;
}