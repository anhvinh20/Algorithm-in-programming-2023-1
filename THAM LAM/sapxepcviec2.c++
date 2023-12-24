// Cho n công việc, được biểu diễn <JobID,Deadline,Profit>
// Tính lợi nhuận lớn nhất có thể thực hiện vs việc thực hiện mỗi việc đơn lẻ
// Nhập t bộ test , n jobs , và n bộ <JobID,Deadline,Profit>
// In ra số lượng công việc tương ứng và lợi nhuận max

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc để lưu thông tin công việc, bao gồm job ID, deadline và lợi nhuận.
struct Job {
    int id, deadline, profit;
};

// Hàm so sánh để sắp xếp các công việc dựa trên lợi nhuận giảm dần.
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Hàm chính để tìm phương án thực hiện công việc tối ưu.
void findMaxProfit(vector<Job>& jobs) {
    // Sắp xếp công việc dựa trên lợi nhuận.
    sort(jobs.begin(), jobs.end(), compare);

    int result[jobs.size()]; // Mảng lưu các công việc được chọn.
    bool slot[jobs.size()]; // Mảng kiểm tra slot thời gian đã được sử dụng hay chưa.

    // Khởi tạo tất cả các slot là chưa sử dụng.
    fill(slot, slot + jobs.size(), false);

    int countJobs = 0, totalProfit = 0; // Biến đếm số công việc và tổng lợi nhuận.

    // Duyệt qua từng công việc để xem xét.
    for (int i = 0; i < jobs.size(); i++) {
        // Tìm slot từ deadline của công việc, lùi về đến 0.
        for (int j = min((int)jobs.size(), jobs[i].deadline) - 1; j >= 0; j--) {
            // Nếu slot chưa được sử dụng, gán công việc vào slot này.
            if (!slot[j]) {
                result[j] = i; // Lưu ID của công việc vào slot.
                slot[j] = true; // Đánh dấu slot đã được sử dụng.
                countJobs++; // Tăng số công việc được chọn.
                totalProfit += jobs[i].profit; // Tăng tổng lợi nhuận.
                break; // Kết thúc vòng lặp khi đã gán xong công việc.
            }
        }
    }

    // In ra số lượng công việc tối đa và tổng lợi nhuận.
    cout << countJobs << " " << totalProfit << endl;
}

int main() {
    int t; // Số lượng bộ test.
    cin >> t;
    while (t--) {
        int n; // Số lượng công việc.
        cin >> n;
        vector<Job> jobs(n);

        // Đọc thông tin của từng công việc.
        for (int i = 0; i < n; i++) {
            cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        }

        // Tìm và in ra phương án tối ưu.
        findMaxProfit(jobs);
    }
    return 0;
}
