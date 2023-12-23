// Nhập vào 2 khối, khối 1 là thông tin kết thúc bằng * . Khối 2 là hoạt động ( find - từ khối 1 ) 
// hoăc (insert- vào khối 1) kết thúc bằng ***
// In ra 1 nếu thực hiện dc , 0 nếu false

//C++ 
#include<iostream>
#include<map>
using namespace std;

map<string, int> mp;  // chuyển chuỗi kí tự sang số nguyên

void init() {
	string input;
	cin >> input;
	while (input.compare("*")!=0) {
		mp[input] = 1;       // Đọc chuỗi và lưu vào mapp ( giá trị mặc định là 1 )
		cin >> input;
	}
}

void query() {
	string input;    // Nếu là find hàm chuyển sang đọc giá trị tiếp theo 
	cin >> input;
	while (input.compare("***")!=0) {
		string arg;
		cin >> arg;
		if (input.compare("find")==0) {
			cout << mp[arg] << endl;
		} else {
			cout << !mp[arg] << endl;
			mp[arg] |= 1;          // Phép OR . Nếu arg đã tồn tại và giá trị của nó = 0 --> thành 1
                                   //                                                = 1 --> giữu nguyên 1
		}
		cin >> input;
	}
}

int main() {
	init();
	query();
}
