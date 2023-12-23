// Một hcn n*m ( 0 là trắng , 1 là đen )
// Tính diện tích ô trắng lớn nhất
// Nhập vào n,m, mảng A[n][m]
// Ghi ra diện tích lớn nhất của hcn

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int n, m;
int a[MAX][MAX];
int l[MAX][MAX], r[MAX][MAX], h[MAX][MAX];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) { // Nếu ô hiện tại là trắng, reset chiều cao.
                h[i][j] = 0;
            } else { // Ngược lại, cập nhật chiều cao và rộng của hình chữ nhật.
                h[i][j] = h[i - 1][j] + 1;   // Chiều cao Ô dưới = Chiều cao ô phía trên +1
            }
        }
    }
}

void solve() {
    int area_max = 0;

    for (int i = 1; i <= n; ++i) {    // Duyện từ trên xuống dưới của 1 cột
        stack<int> s;
        for (int j = 1; j <= m; ++j) { // Duyện từ trái sang phải
            while (!s.empty() && h[i][s.top()] >= h[i][j]) s.pop();
            l[i][j] = (s.empty()) ? 1 : s.top() + 1;    // Nếu ngăn xếp rỗng--> ko có cột nào bên trái --> l[i][j] =1 
            s.push(j);                                  // Nếu ko rỗng, l[i][j] là vị trí ngay cột đỉnh ngăn xếp
        }
        while (!s.empty()) s.pop();

        for (int j = m; j >= 1; --j) { 
            while (!s.empty() && h[i][s.top()] >= h[i][j]) s.pop();
            r[i][j] = (s.empty()) ? m : s.top() - 1;
            s.push(j);

            area_max = max(area_max, h[i][j] * (r[i][j] - l[i][j] + 1)); // Tính diện tích
        }
    }

    cout << area_max << endl;
}

int main() {
    ios::sync_with_stdio(false); // Tăng tốc độ xử lý nhập/xuất.
    cin.tie(NULL);

    input();
    solve();

    return 0;
}
