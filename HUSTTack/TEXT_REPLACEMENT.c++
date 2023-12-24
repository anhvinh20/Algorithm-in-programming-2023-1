// Thay thế sâu P1 trong T bằng sâu P2
// Nhập P1 ,  P2 , T
// In ra T

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string replaceAll(string text, string s1, string s2) {
	int found = text.find(s1);
	while (found != string::npos) {
		text.replace(found, s1.length(), s2);
		found = text.find(s1);
	}
	return text;
}

int main() {
	string text, s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, text);
	cout << replaceAll(text, s1, s2);
	return 0;
}
