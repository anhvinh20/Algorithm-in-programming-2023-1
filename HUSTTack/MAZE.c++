#include<bits/stdc++.h>
using namespace std;
int n, m, a[100][100];
int r, c;
bool ok[100][100];
vector<string> res;

void Try(int i, int j, string s) {
    if (j == m && a[i][j]==0) { // Điểm đích là n, m
        res.push_back(s);
        return;
    }
    if (i < n && a[i + 1][j] == 0 && !ok[i + 1][j]) { // Đi xuống
        ok[i][j] = true;
        Try(i + 1, j, s + 'D');
        ok[i][j] = false;
    }
    if (j < m && a[i][j + 1] == 0 && !ok[i][j + 1]) { // Đi sang phải
        ok[i][j] = true;
        Try(i, j + 1, s + 'R');
        ok[i][j] = false;
    }
    if (i > 1 && a[i - 1][j] == 0 && !ok[i - 1][j]) { // Đi lên
        ok[i][j] = true;
        Try(i - 1, j, s + 'U');
        ok[i][j] = false;
    }
    if (j > 1 && a[i][j - 1] == 0 && !ok[i][j - 1]) { // Đi sang trái
        ok[i][j] = true;
        Try(i, j - 1, s + 'L');
        ok[i][j] = false;
    }
}

void Solve() {
    memset(ok, false, sizeof(ok));
    res.clear();
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    if (a[r][c] == 1 || a[n][m] == 1) {
        cout << -1 << endl;
        return;
    }
    Try(r, c, "");
    if (res.empty()) {
        cout << -1;
    } else {
        sort(res.begin(), res.end());
        for (const string& path : res) {
            cout << path << " ";
        }
    }
    cout << endl;
}

int main() {
    Solve();
    return 0;
}
