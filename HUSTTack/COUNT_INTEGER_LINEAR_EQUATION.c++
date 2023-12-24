// Nhập vào n ,m sao cho ( a1X1+a2X2+...+a3X3 = M )
// Nhập a1,a2,a3....
// In ra số nghiệm nguyên dương

#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
vector<int> a;
vector<int> x;
int sum;
int count;

void TRY(int i);

void solve() {
    cin >> n >> m;
    a.resize(n);
    x.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sum = 0;
    count = 0;
    TRY(0);
    cout << count << endl;
}

void TRY(int i) {
    for (int v = 1; v <= m / a[i]; v++) {
        if (sum + a[i] * v > m) return;
        x[i] = v;
        sum += a[i] * x[i];

        if (i == n - 1) {
            if (sum == m) count++;
        } else {
            TRY(i + 1);
        }

        sum -= a[i] * x[i];
    }
}

int main() {
    solve();
    return 0;
}
