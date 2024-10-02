#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> st; // Bảng Sparse Table
int n, lg;

void buildSparseTable(const vector<int>& arr) {
    n = arr.size();
    lg = log2(n) + 1;
    st.resize(n, vector<int>(lg));

    // Khởi tạo cột đầu tiên
    for (int i = 0; i < n; ++i) {
        st[i][0] = arr[i];
    }

    // Xây dựng Sparse Table
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Hàm tìm giá trị nhỏ nhất trong khoảng [L, R]
int rmq(int L, int R) {
    int j = log2(R - L + 1);
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    // Đọc dữ liệu vào mảng
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    buildSparseTable(arr);

    int m;
    cin >> m;
    long long Q = 0;

    // Xử lý các truy vấn
    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        Q += rmq(i, j);
    }

    // In kết quả
    cout << Q << endl;
    return 0;
}
