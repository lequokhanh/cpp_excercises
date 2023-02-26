#pragma once

class SoPhuc {
    private:
        float fThuc, fAo;
    public:
        SoPhuc ();
        SoPhuc (float fThuc, float fAo);
        void Nhap ();
        void Xuat ();
        void LayTuSo ();
        SoPhuc Cong (SoPhuc x);
        SoPhuc Tru (SoPhuc x);
        SoPhuc Nhan (SoPhuc x);
        SoPhuc Chia (SoPhuc x);
        float gttd ();
};