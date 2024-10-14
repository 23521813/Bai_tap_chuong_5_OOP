#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(100001);
const int mod = 1e9 + 7;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

class PhanSo {
private:
    int tuso;
    int mauso;

public:
    PhanSo(int t = 0, int m = 1) : tuso(t), mauso(m) {}
    PhanSo(const PhanSo &p) {
        tuso = p.tuso;
        mauso = p.mauso;
    }
    int LayTu() const {
        return tuso;
    }
    int LayMau() const {
        return mauso;
    }
    void GanTu(int t) {
        tuso = t;
    }
    void GanMau(int m) {
        mauso = m;
    }
    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuso;
        cout << "Nhap mau so: ";
        cin >> mauso;
    }
    void Xuat() const {
        cout << tuso << "/" << mauso << endl;
    }
    bool operator>(const PhanSo &p) const {
        return tuso * p.mauso > p.tuso * mauso;
    }
    PhanSo operator+(const PhanSo &p) const {
        PhanSo result;
        result.tuso = tuso * p.mauso + p.tuso * mauso;
        result.mauso = mauso * p.mauso;
        return result;
    }
    PhanSo operator-(const PhanSo &p) const {
        PhanSo result;
        result.tuso = tuso * p.mauso - p.tuso * mauso;
        result.mauso = mauso * p.mauso;
        return result;
    }
};

class DSPhanSo {
private:
    PhanSo* ds;
    int n;
public:
    // Constructor để khởi tạo mảng phân số
    DSPhanSo(int size) {
        n = size;
        ds = new PhanSo[n];
    }
    // Destructor để giải phóng bộ nhớ
    ~DSPhanSo() {
        delete[] ds;
    }
    // Nhập phân số cho mảng
    void NhapDS() {
        for (int i = 0; i < n; ++i) {
            cout << "Nhap phan so thu " << i + 1 << ":\n";
            ds[i].Nhap();
        }
    }
    // Tìm phân số lớn nhất trong mảng
    PhanSo TimPhanSoLonNhat() {
        PhanSo max = ds[0];
        for (int i = 1; i < n; ++i) {
            if (ds[i] > max) {
                max = ds[i];
            }
        }
        return max;
    }
    // Tính tổng các phân số trong mảng
    PhanSo TinhTong() {
        PhanSo tong;
        for (int i = 0; i < n; ++i) {
            tong = tong + ds[i];
        }
        return tong;
    }
};

int32_t main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    DSPhanSo ds(n);
    // Nhập các phân số
    ds.NhapDS();
    // Tìm và in phân số lớn nhất
    PhanSo max = ds.TimPhanSoLonNhat();
    cout << "Phan so lon nhat: ";
    max.Xuat();
    // Tính tổng các phân số và in kết quả
    PhanSo tong = ds.TinhTong();
    cout << "Tong cac phan so: ";
    tong.Xuat();
    return 0;
}
