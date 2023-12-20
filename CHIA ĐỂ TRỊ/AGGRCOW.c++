// Xây chuồng bò với n ngăn. Các ngăn được xếp theo 1 đường tại vị trí x1, x2 ,...
// Nuôi C con bò ( bò không xếp cạnh nhau ). Tính khaongr cách ngắn nhất giữa 2 con bất kì là lớn nhất có thế?
// Dòng 1 nhập số test t
// DÒng 2 nhập n c
// Dòng n+1 :nhập xi là vị trí chuồng thứ i 
// Đầu ra : khoảng cách ngắn nhất giữa 2 con bki laf lớn nhất
// Ví dụ 5 3 ( 1 2 8 4 9 ) --> 3 con bò ở 1 , 4 , 9 ( đầu ra là 3)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkDistance(vector<int>& positions, int cows, int distance) {
    int count = 1;
    int lastPosition = positions[0];

    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i] - lastPosition >= distance) { // >= distance vì distance phải là khoảng cách bé nhất của con bò
            lastPosition = positions[i];
            count++;
        }
    }

    return count >= cows;
}

int maxMinDistance(vector<int>& positions, int cows) {
    sort(positions.begin(), positions.end());

    int low = 0;
    int high = positions.back() - positions.front();   // vị trí cuối cùng của chuồng N - vị trí đâu tiên của chuồng
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (checkDistance(positions, cows, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, c;
        cin >> n >> c;

        vector<int> positions(n);
        for (int j = 0; j < n; ++j) {
            cin >> positions[j];
        }

        int result = maxMinDistance(positions, c);
        cout << result << endl;
    }

    return 0;
}
