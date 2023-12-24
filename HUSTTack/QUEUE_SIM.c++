// Đây là 1 QUEUE ( hàng đợi ) 
// Nhập vào PUSH 1 , PUSH 2 ( để đưa và0); POP ( để lấy ra)
// Nhập đến # thì dừng


#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> s;
    string input;
    cin >> input;
    while (input != "#")
    {
        if (input == "PUSH")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else
        {
            if (!s.empty())
            {
                cout << s.front() << endl; // Lấy ra giá trị đầu queue
                s.pop();
            }
            else
                cout << "NULL" << endl;
        }
        cin >> input;
    }
}