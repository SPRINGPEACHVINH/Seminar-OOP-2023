#include <iostream>

using namespace std;

// Khai báo trước
class HinhTron;
class HinhVuong;

// Giao diện Visitor
class KhachThamQuan
{
public:
    virtual void thamQuan(HinhTron &hinhTron) = 0;
    virtual void thamQuan(HinhVuong &hinhVuong) = 0;
};

// Giao diện Element
class Hinh
{
public:
    virtual void chaoDon(KhachThamQuan &khachThamQuan) = 0;
};

// Hình Tròn
class HinhTron : public Hinh
{
public:
    void chaoDon(KhachThamQuan &khachThamQuan) override
    {
        khachThamQuan.thamQuan(*this);
    }

    void veHinhTron()
    {
        cout << "Ve hinh tron" << endl;
    }
};

// Hình Vuông
class HinhVuong : public Hinh
{
public:
    void chaoDon(KhachThamQuan &khachThamQuan) override
    {
        khachThamQuan.thamQuan(*this);
    }

    void veHinhVuong()
    {
        cout << "Ve hinh vuong" << endl;
    }
};

// Khách tham quan cụ thể
class KhachThamQuanCuThe : public KhachThamQuan
{
public:
    void thamQuan(HinhTron &hinhTron) override
    {
        cout << "Tham quan hinh tron" << endl;
        hinhTron.veHinhTron();
    }

    void thamQuan(HinhVuong &hinhVuong) override
    {
        cout << "Tham quan hinh vuong" << endl;
        hinhVuong.veHinhVuong();
    }
};

int main()
{
    HinhTron hinhTron;
    HinhVuong hinhVuong;

    KhachThamQuanCuThe khachThamQuan;

    hinhTron.chaoDon(khachThamQuan);
    hinhVuong.chaoDon(khachThamQuan);

    return 0;
}
