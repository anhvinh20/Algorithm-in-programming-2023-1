// Nhập vào n, M,  dãy số nguyên a[n] phần tử ( đôi một khác nhau )
// Đếm các cặp Q(i,j) sao cho a[i]+a[j] = M

#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int count = 0;     // Đếm số cặp phù hợp
    int left = 0, right = n - 1;

    // Sử dụng hai con trỏ để tìm các cặp phù hợp
    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == M) {
            ++count;
            ++left;
            --right;
        } else if (sum < M) {
            ++left;
        } else {
            --right;
        }
    }

    cout << count << endl;
    return 0;
}
