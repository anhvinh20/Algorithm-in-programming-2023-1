// Đếm số lần gặp lại của chuỗi P có trong T
// Nhập chuỗi P , T

#include<iostream>
using namespace std;

int main() {
	string t, p;
	getline(cin, p);
	getline(cin, t);
	
	int count = 0;
	int found = 0;
	while ((found = t.find(p, found)) != string::npos) { // Lặp cho đến khi ko tìm thấy p trong t nưuax
		count++;
		t.replace(found, p.length(), "");  // Thay thế p bằng t bằng chuỗi rỗng, xóa p khỏi t 
	}
	cout << count;
	
	return 0;
}
