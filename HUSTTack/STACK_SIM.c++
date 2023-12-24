// Đây là 1 STACK 
// Nhập vào PUSH 1 , PUSH 2 ( để đưa và0); POP ( để lấy ra)
// Nhập đến # thì dừng

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
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
                int tmp = s.top();
                s.pop();
                cout << tmp << endl;
            }
            else
                cout << "NULL" << endl;
        }
        cin >> input;
    }
}
