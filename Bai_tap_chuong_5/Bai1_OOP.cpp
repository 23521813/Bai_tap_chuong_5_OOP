/**
 *    author:  longvu
 *    created: 10/14/24 20:10:59
**/
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

class ComplexNumber {
private:
    double p;  // Phần thực
    double q;  // Phần ảo

public:
    // Constructor mặc định và constructor với tham số
    ComplexNumber(double r = 0.0, double i = 0.0) : p(r), q(i) {}

    // Phép cộng hai số phức
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(p + other.p, q + other.q);
    }

    // Phép trừ hai số phức
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(p - other.p, q - other.q);
    }

    // Phép nhân hai số phức
    ComplexNumber operator*(const ComplexNumber& other) const {
        double p_part = p * other.p - q * other.q;
        double q_part = p * other.q + q * other.p;
        return ComplexNumber(p_part, q_part);
    }

    // Phép chia hai số phức
    ComplexNumber operator/(const ComplexNumber& other) const {
        double denominator = other.p * other.p + other.q * other.q;
        double p_part = (p * other.p + q * other.q) / denominator;
        double q_part = (q * other.p - p * other.q) / denominator;
        return ComplexNumber(p_part, q_part);
    }

    // Phép so sánh bằng hai số phức
    bool operator==(const ComplexNumber& other) const {
        return (p == other.p) && (q == other.q);
    }

    // Nhập số phức
    friend istream& operator>>(istream& in, ComplexNumber& c) {
        cout << "Nhap phan thuc: ";
        in >> c.p;
        cout << "Nhap phan ao: ";
        in >> c.q;
        return in;
    }

    // Xuất số phức
    friend ostream& operator<<(ostream& out, const ComplexNumber& c) {
        out << c.p << " + " << c.q << "i";
        return out;
    }
};

int32_t main() {
    ComplexNumber c1(3, 4);
    ComplexNumber c2(1, -2);
    cout << "So phuc c1: " << c1 << endl;
    cout << "So phuc c2: " << c2 << endl;
    ComplexNumber sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;
    ComplexNumber diff = c1 - c2;
    cout << "c1 - c2 = " << diff << endl;
    ComplexNumber prod = c1 * c2;
    cout << "c1 * c2 = " << prod << endl;
    ComplexNumber quot = c1 / c2;
    cout << "c1 / c2 = " << quot << endl;
    if (c1 == c2) {
        cout << "c1 va c2 bang nhau" << endl;
    } else {
        cout << "c1 va c2 khong bang nhau" << endl;
    }
    return 0;
}
