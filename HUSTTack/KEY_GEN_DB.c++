// Nhập n (khóa) , L (chiều dài cố định), m (khóa sẽ sinh)
// In ra m khóa mới ( bao gồm cả khóa cũ )

#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;

map<int, int> mp; // Sử dụng map để lưu trữ các số, với key là số và value là 1 nếu số đó đã tồn tại.
int n, L, m; // n là số lượng số cần nhập, L là chiều dài số để in ra, m là số lượng số cần phát sinh thêm.
stringstream ss; // Sử dụng stringstream để chuyển đổi giữa string và số.

void input() {
    cin >> n >> L >> m; // Nhập số lượng số, chiều dài số và số lượng số cần phát sinh.
    string s;
    int x;
    for (int i=0; i<n; i++) {
        ss.clear(); ss.str(""); // Làm sạch và reset stringstream.
        cin >> s; ss << s; ss >> x; // Đọc một chuỗi, sau đó dùng stringstream để chuyển đổi sang số nguyên.
        mp[x] = 1; // Đánh dấu số này đã tồn tại trong map.
    }
}

void generate() {
    int count = 0;
    int key = 1;
    while (count<m) { // Lặp cho đến khi tạo đủ m số mới.
        if (mp[key]==0) { // Nếu số này chưa tồn tại trong map.
            mp[key] = 1; // Đánh dấu là đã tồn tại.
            count++; // Tăng số lượng số đã phát sinh.
        }
        key++; // Tăng key để kiểm tra số tiếp theo.
    }
}

void output() {
    int count=0, key=1;
    while (count<n+m) { // In ra tổng cộng n+m số.
        if (mp[key]==1) { // Nếu số này tồn tại trong map.
            ss.clear(); ss.str(""); // Làm sạch và reset stringstream.
            ss << key; // Đưa số vào stringstream.
            string s = ss.str(); // Chuyển số thành chuỗi.
            for (int k=0; k<L-s.length(); k++) cout << "0"; // In ra số 0 cần thiết để đạt chiều dài L.
            cout << s << endl; // In ra số.
            count++; // Tăng số lượng số đã in.
        }
        key++; // Tăng key để kiểm tra số tiếp theo.
    }
}

int main() {
    input(); // Gọi hàm nhập liệu.
    generate(); // Gọi hàm sinh số mới.
    output(); // Gọi hàm in kết quả.
    return 0;
}

