//Có n hành khách được đánh số từ 1 đến n, hành kahcsh thứ i cần di chuyển từ điểm i đến i+n
// Taxi từ điểm 0, ma trận khoảng cách c(2n+1)(2n+1) 
// taxi cần tính đường đi  ngắn nhất để phục vụ tất cả n khách và quay trở lại điểm 0
// sao cho ko có nhiều hơn 1 hành khách trên xe ( bki thời điểm nào ) + ko điểm nào dc viếng thắm > 1 lần

// Nhập n số khách, nhập mảng c(2n+1)(2n+1) 
// Đầu ra : Độ dài tuyến đường đi ngắn nhất

#include<bits/stdc++.h>

#define MAX 23
using namespace std;

int n;
int c[MAX][MAX];
bool visited[MAX];
int x[MAX];
int f;
int f_min = INT_MAX;
int c_min = INT_MAX;

void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            visited[v] = true;
            x[k] = v;
            x[k + 1] = v + n;
            f += c[x[k - 1]][x[k]] + c[x[k]][x[k + 1]];
            if (k == 2 * n - 1) {
                f_min = min(f_min, f + c[x[k + 1]][0]);
            } else {
                if (f + (2 * n - k) * c_min <= f_min) Try(k + 2);
            }
            visited[v] = false;
            f -= c[x[k - 1]][x[k]] + c[x[k]][x[k + 1]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> c[i][j];
            c_min = min(c_min, c[i][j]);
        }
        visited[i] = false;
    }
    x[0] = 0;
    Try(1);
    cout << f_min;
    return 0;
}
