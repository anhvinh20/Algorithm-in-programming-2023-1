// Cho hệ gồm n hành động. Mỗi hành động được biểu diễn như bộ đôi <Si,Fi>
// tương ứng tgian bắt đầu, kết thúc. Tìm phương án thực hiện nhiều nhất hành động
// để ko xảy ra mâu thuẫn
// Nhập t bộ test, số hành động n , n số Si ( tgian bắt đầu ), n số Fi (tgian kết thúc)
// Đầu ra : Số lượng lớn nhất các hành động có thể được thực thi bởi một máy tính 
// hoặc một người


#include<bits/stdc++.h>
using namespace std;
struct Activity {
    int start, end;   // Thời gian bắt đầu và thời gian kết thúc việc
};
// So sánh để xếp các hoạt động
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int maxActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare); // sắp xếp các hoạt động
    int count = 1; // Bắt đầu với công việc đầu tiên
    int lastEnd = activities[0].end;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end; // cập nhập tgian kết thúc của hoạt động
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Activity> activities(n);
        for (int i = 0; i < n; i++) {
            cin >> activities[i].start;
        }
        for (int i = 0; i < n; i++) {
            cin >> activities[i].end;
        }

        cout << maxActivities(activities) << endl;
    }
    return 0;
}