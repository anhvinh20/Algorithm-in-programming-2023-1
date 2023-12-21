#include<bits/stdc++.h>
using namespace std;
int n, a[100][100];
bool ok[100][100];
vector<string> res;

void Try(int i, int j, string s) {
    if (i == n && j == n) {
        res.push_back(s);
        return;
    }
    if (i < n && a[i + 1][j]==1 && !ok[i + 1][j]) { // Đi xuống
        ok[i][j] = true;                            // đánh dấu nó đã đi
        Try(i + 1, j, s + 'D');                     // Đi xuống
        ok[i][j] = false;                           // Trả lại là chưa đi
    }
    if (j < n && a[i][j + 1]==1 && !ok[i][j + 1]) { // Đi sang phải
        ok[i][j] = true;
        Try(i, j + 1, s + 'R');
        ok[i][j] = false;
    }
    if (i > 1 && a[i - 1][j]==1 && !ok[i - 1][j]) { // Đi lên
        ok[i][j] = true;
        Try(i - 1, j, s + 'U');
        ok[i][j] = false;
    }
    if (j > 1 && a[i][j - 1]==1 && !ok[i][j - 1]) { // Đi sang trái
        ok[i][j] = true;
        Try(i, j - 1, s + 'L');
        ok[i][j] = false;
    }
}

void Solve() {
    memset(ok, false, sizeof(ok)); //Cho tất cả mảng ok bằng false
    res.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == 0 || a[n][n] == 0) { // Nếu bắt đầu hoặc kết thúc bằng 0 thì -1 luôn
        cout << -1 << endl;
        return;
    }
    ok[1][1] = true; // Daansh đấu điểm đầu tiên đã đi qua
    Try(1, 1, "");
    if (res.empty()) { // Không có dòng nào thì ra -1
        cout << -1;
    } else {
        sort(res.begin(), res.end());
        for (string str : res) {
            cout << str << ' ';
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
