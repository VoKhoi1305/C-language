#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> table;
int n, lg;

void processing(const vector<int>& arr) {
    n = arr.size();
    lg = log2(n) + 1;
    table.resize(n, vector<int>(lg));

    for (int i = 0; i < n; ++i) {
        table[i][0] = arr[i];
    }


    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int L, int R) {
    int j = log2(R - L + 1);
    return min(table[L][j], table[R - (1 << j) + 1][j]);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    processing(arr);

    int m;
    cin >> m;
    long long Q = 0;

    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        Q += rmq(i, j);
    }

    cout << Q << endl;
    return 0;
}
