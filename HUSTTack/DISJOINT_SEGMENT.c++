// Nhập vào n và n số cặp X=(a1,b1);(a2,b2)....
// Tìm mootj tập con của X có số lượng lớn nhất trong đó 
// ko có 2 đoạn nào của tập con cắt nhau
// Nhập 6 :   0 10 ; 3 7 ; 6 14 ; 9 11 ; 12 15 ; 17 19 --> 4
// Đầu ra : Số lượng phân đoạn trong giải pháp

#include <bits/stdc++.h> 
using namespace std;
// Định nghĩa cấu trúc cho Đoạn thẳng với điểm đầu và điểm cuối.
struct Segment {
    int start, end;
};

// Hàm so sánh để sắp xếp các đoạn thẳng theo điểm cuối.
bool compareSegments(const Segment &a, const Segment &b) {
    return a.end < b.end;
}

// Hàm tìm số lượng đoạn thẳng không giao nhau nhiều nhất.
int maxNonIntersectingSegments(vector<Segment> &segments) {
    // Sắp xếp các đoạn thẳng theo điểm cuối.
    sort(segments.begin(), segments.end(), compareSegments);

    // 'last' để theo dõi điểm cuối của đoạn thẳng cuối cùng được thêm vào tập hợp con.
    int last = -1;
    int count = 0;

    // Lặp qua các đoạn thẳng.
    for (const Segment &s : segments) {
        // Nếu đoạn thẳng hiện tại không giao với đoạn thẳng được thêm vào trước đó, thì bao gồm nó.
        if (s.start > last) {
            last = s.end;
            count++;
        }
    }

    // Trả về số lượng đoạn thẳng không giao nhau.
    return count;
}

int main() {
    // Đọc số lượng đoạn thẳng.
    int n;
    cin >> n;

    vector<Segment> segments(n);

    // Đọc các đoạn thẳng.
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].start >> segments[i].end;
    }

    // Tính toán và in ra kết quả.
    cout << maxNonIntersectingSegments(segments) << endl;

    return 0;
}
