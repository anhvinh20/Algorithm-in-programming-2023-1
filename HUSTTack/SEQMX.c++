// Nhập vào n số nguyên, k (dãy con có ít nhất từng này phần tử)
// Nhập vào dãy số nguyên a[i]
// Ghi ra trung bình cộng lớn nhất của dãy con

#include <bits/stdc++.h> 
using namespace std;
#include <iomanip> // Để sử dụng setprecision

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Tính tổng ban đầu cho k phần tử đầu tiên
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += a[i];
    }

    long long max_sum = sum;
    // Quét qua dãy số để tìm tổng lớn nhất của dãy con có ít nhất k phần tử
    for (int i = k; i < n; ++i) {
        sum += a[i] - a[i - k];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    // In ra trung bình cộng lớn nhất với độ chính xác 5 chữ số thập phân
    cout << fixed << setprecision(5) << static_cast<double>(max_sum) / k << endl;

    return 0;
}
