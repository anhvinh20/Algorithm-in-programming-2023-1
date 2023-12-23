// Tạo khóa bằng cách nhập vào n ( số lượng số nguyên không âm ) , L là độ dài cố định của khóa
// Nhập dãy số nguyên . Với  L=5 thì khóa từ 123 --> 00123

#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

int main() {
	int n, L;
	cin >> n >> L;
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		for (int k=0; k<L-s.length(); k++) {
			cout << "0";
		}
		cout << s << endl;
	}
	return 0;
}
