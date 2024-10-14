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

class MaTran {
private:
    int m, n;
    vector<vector<int>> mat;
public:
    // Khởi tạo ma trận ngẫu nhiên m dòng, n cột
    MaTran(int rows, int cols) {
        m = rows;
        n = cols;
        mat.resize(m, vector<int>(n)); // Khởi tạo kích thước ma trận
    }

    // Hàm nhập ma trận từ bàn phím
    void Nhap() {
        cout << "So phan tu cua ma tran (" << m << "x" << n << "):\n";
        cout << "Nhap ma tran: " << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    // Hàm tạo ma trận với các giá trị ngẫu nhiên
    void TaoNgauNhien() {
        srand(time(0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = rand() % 100;
            }
        }
    }

    // Cộng hai ma trận
    MaTran operator+(const MaTran& other) {
        MaTran result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    MaTran operator-(const MaTran& other) {
        MaTran result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    // Nhân hai ma trận
    MaTran operator*(const MaTran& other) {
        MaTran result(m, other.n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < other.n; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < n; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const MaTran& mt) {
        for (int i = 0; i < mt.m; ++i) {
            for (int j = 0; j < mt.n; ++j) {
                os << mt.mat[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

int32_t main() {
    int m, n, p;
    cout << "Nhap so hang, so cot ma tran 1: "  << endl;
    cin >> m >> n;
    MaTran mat1(m, n);
    mat1.Nhap();
    cout << "Nhap so hang, so cot ma tran 2: "  << endl;
    cin >> m >> n;
    MaTran mat2(m, n);
    mat2.Nhap();
    mat1 = mat1 + mat2;
    cout << "Cong 2 ma tran: " << endl;
    cout << mat1 << endl;
    mat1 = mat1 - mat2;
    cout << "Tru 2 ma tran: " << endl;
    cout << mat1 << endl;
    mat1 = mat1 * mat2;
    cout << "Nhan 2 ma tran: " << endl;
    cout << mat1 << endl;
    return 0;
}
