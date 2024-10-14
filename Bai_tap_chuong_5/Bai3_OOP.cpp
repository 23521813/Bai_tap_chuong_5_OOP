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

class DaThuc {
private:
    int bac; // Bậc của đa thức
    vector<double> heso; // Các hệ số của đa thức

public:
    // Khởi tạo đa thức bậc 0
    DaThuc() {
        bac = 0;
        heso.push_back(0);
    }

    // Khởi tạo đa thức bậc n
    DaThuc(int n) {
        bac = n;
        heso.resize(n + 1); // Kích thước của mảng hệ số
    }

    // Hàm nhập các hệ số của đa thức
    void Nhap() {
        cout << "Nhap he so " << endl;
        for (int i = bac; i >= 0; --i) {
            cout << "He so bac " << i << ": ";
            cin >> heso[i];
        }
    }

    // Tính giá trị của đa thức tại giá trị x
    double TinhGiaTri(double x) {
        double result = 0;
        for (int i = bac; i >= 0; --i) {
            result += heso[i] * pow(x, i);
        }
        return result;
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& is, DaThuc& dt) {
        cout << "Nhap bac: ";
        is >> dt.bac;
        dt.heso.resize(dt.bac + 1);
        cout << "Nhap he so" << endl;
        for (int i = dt.bac; i >= 0; --i) {
            cout << "He so bac " << i << ": ";
            is >> dt.heso[i];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const DaThuc& dt) {
        for (int i = dt.bac; i >= 0; --i) {
            os << dt.heso[i] << "x^" << i << " ";
            if (i) os << "+ ";
        }
        return os;
    }

    DaThuc operator+(const DaThuc& dt) {
        int maxBac = max(bac, dt.bac);
        DaThuc result(maxBac);
        for (int i = 0; i <= maxBac; ++i) {
            double h1 = (i <= bac) ? heso[i] : 0; // Hệ số của đa thức 1
            double h2 = (i <= dt.bac) ? dt.heso[i] : 0; // Hệ số của đa thức 2
            result.heso[i] = h1 + h2;
        }
        return result;
    }

    // Toán tử trừ hai đa thức
    DaThuc operator-(const DaThuc& dt) {
        int maxBac = max(bac, dt.bac);
        DaThuc result(maxBac);
        for (int i = 0; i <= maxBac; ++i) {
            double h1 = (i <= bac) ? heso[i] : 0; // Hệ số của đa thức 1
            double h2 = (i <= dt.bac) ? dt.heso[i] : 0; // Hệ số của đa thức 2
            result.heso[i] = h1 - h2;
        }
        return result;
    }
};

int32_t main() {
    DaThuc dt1;
    cout << "Da thuc 1:" << endl;
    cin >> dt1;
    cout << dt1 << endl;
    DaThuc dt2;
    cout << "Da thuc 2:" << endl;
    cin >> dt2;
    cout << dt2 << endl;
    double x;
    cout << "Nhap gia tri x: " << endl;
    cin >> x;
    cout << "Gia tri cua da thuc 1 khi x = " << x << " la: " << dt1.TinhGiaTri(x) << endl;
    DaThuc tong = dt1 + dt2;
    cout << "Tong: " << tong << endl;
    DaThuc hieu = dt1 - dt2;
    cout << "Hieu: " << hieu << endl;
    return 0;
}
