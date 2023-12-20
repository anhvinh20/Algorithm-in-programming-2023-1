//Tổng tối đa sao cho không có hai phần tử nào liền kề (Stickler Thief)
// Cho một mảng arr[] gồm các số dương, Nhiệm vụ là tìm tổng lớn nhất của một dãy con sao cho không có 2 số nào trong dãy liền kề nhau trong mảng.
// Ví dụ Đầu vào: arr[] = {3, 2, 7, 10}
//       Đầu ra: 13
//       Giải thích: Dãy con là {3, 10}. Điều này cho ra tổng = 13.


#include <bits/stdc++.h> 
using namespace std;

// Hàm chia để trị
int maxSumRecursive(vector<int>& nums, int start, int end) {
    if (start > end) {
        return 0;
    }

    int includeCurrent = nums[start] + maxSumRecursive(nums, start + 2, end);
    int excludeCurrent = maxSumRecursive(nums, start + 1, end);

    return max(includeCurrent, excludeCurrent);
}

// Hàm gọi chia để trị
int maxSum(vector<int>& nums) {
    return maxSumRecursive(nums, 0, nums.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = maxSum(nums);
    cout << result << endl;

    return 0;
}
