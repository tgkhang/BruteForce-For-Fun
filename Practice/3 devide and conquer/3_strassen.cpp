#include<iostream>
#include<vector>


using namespace std;

int n;

vector<vector<int>> strassen(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    if (n == 2) {
        c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
        c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
        c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
        c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
        return c;
    }
    else if (n == 1) {
        c[0][0] = a[0][0] * b[0][0];
        return c;
    }
    
    int k = n / 2;

    // Initialize submatrices
    vector<vector<int>> a11(k, vector<int>(k)), a12(k, vector<int>(k)), a21(k, vector<int>(k)), a22(k, vector<int>(k));
    vector<vector<int>> b11(k, vector<int>(k)), b12(k, vector<int>(k)), b21(k, vector<int>(k)), b22(k, vector<int>(k));


    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }
    }
    // Helper lambda for matrix addition/subtraction
    auto add = [](const vector<vector<int>>& x, const vector<vector<int>>& y) {
        int sz = x.size();
        vector<vector<int>> res(sz, vector<int>(sz));
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                res[i][j] = x[i][j] + y[i][j];
        return res;
    };
    auto sub = [](const vector<vector<int>>& x, const vector<vector<int>>& y) {
        int sz = x.size();
        vector<vector<int>> res(sz, vector<int>(sz));
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                res[i][j] = x[i][j] - y[i][j];
        return res;
    };
    // Strassen's 7 products
    auto m1 = strassen(add(a11, a22), add(b11, b22));
    auto m2 = strassen(add(a21, a22), b11);
    auto m3 = strassen(a11, sub(b12, b22));
    auto m4 = strassen(a22, sub(b21, b11));
    auto m5 = strassen(add(a11, a12), b22);
    auto m6 = strassen(sub(a21, a11), add(b11, b12));
    auto m7 = strassen(sub(a12, a22), add(b21, b22));
    // Compute c's submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            c[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
            c[i][j + k] = m3[i][j] + m5[i][j];
            c[i + k][j] = m2[i][j] + m4[i][j];
            c[i + k][j + k] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
        }
    }
    return c;
}

int main()
{
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    vector<vector<int>> c(n, vector<int>(n, 0));

    c= strassen(a, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}