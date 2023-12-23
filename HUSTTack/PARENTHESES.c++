// Cho một chuỗi chỉ chứa các ký tự (, ), [,] {, }. Viết chương trình kiểm tra xem chuỗi biểu thức có đúng hay không.
// Ví dụ : ([]{()}()[]): Chính xác
//         ([]{()]()[]): không đúng
// Đầu vào là chuỗi đó
// Đầu ra là 1 ( nếu đúng ) - 0 ( nếu sai )

#include<bits/stdc++.h>
#include<stack>

using namespace std;

bool matches(char open, char close) {
    if ((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}')) return true;
    return false;
}

bool isValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);           // Duyệt tất cả ngoặc mở vào stack
        } else {
            if (st.empty()) return 0;   // Rỗng thì cút luôn
            char c = st.top();          // Nếu gặp ngoặc đóng, đưa ra phần tử đỉnh để ktra
            st.pop();                   // bằng hàm matches
            if (!matches(c, s[i])) return 0; 
        }
    }
    if (!st.empty()) return 0;       // Sau khi duyệt mà stack rỗng thì đúng, vẫn còn ngoặc thì sai
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << isValid(s);
}
