// Dãy con có tổng là số chẵn lớn nhất 
// Nhập n , nhập mảng 
// Đầu ra : tổng dãy con chẵn lớn nhất hoặc NOT_FOUND

#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_even_subseq_weight = 0;
    long long current_sum = 0;
    bool even_subseq_found = false;

    // Quét qua mảng một lần để tìm tổng lớn nhất
    for (int i = 0; i < n; ++i) {
        current_sum += a[i];

        // Nếu tổng hiện tại là số chẵn và lớn hơn max_even_subseq_weight
        if (current_sum % 2 == 0 && current_sum > max_even_subseq_weight) {
            max_even_subseq_weight = current_sum;
            even_subseq_found = true;
        }

        // Nếu tổng hiện tại là số âm, bắt đầu lại từ tổng 0
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    // In ra
    if (even_subseq_found) {
        cout << max_even_subseq_weight << endl;
    } else {
        cout << "NOT_FOUND" << endl;
    }

    return 0;
}
