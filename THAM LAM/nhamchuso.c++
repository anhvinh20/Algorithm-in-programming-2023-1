// Tèo viết nhầm số 5 thành 6 
//Nhập vào 2 số nguyên và tính tổng , nếu là số 5 thì min , 6 thì max
// Ví dụ : 11 25
// Output : 36 37


#include<bits/stdc++.h>
using namespace std;
string a,b ;
string Sum(){    
    while(a.size() > b.size())  b="0"+b ; // viết thêm 0 để dãy a,b có độ dài bằng nhau
    while(a.size() < b.size())  a="0"+a ;
    string res = "";
    int nho=0;
    int len=a.size();
    for(int i = len-1 ; i>=0 ; i--){
        int so = int(a[i]-'0')+int(b[i]-'0') + nho ;
        res = char(so%10 +'0') + res;
        nho = so/10 ; 
    }
    if(nho>0) res = char(nho+'0') + res;
    return res;
}
int main(){
    int t;
    cin >>t;
    while(t--){
        cin >> a >> b ;
        // Thay 6 thành 5 --> min
        for(int i=0 ; i<a.size() ; i++)
            if(a[i]=='6') a[i]='5' ;
        for(int i=0;i<b.size();i++)
            if(b[i]=='6') b[i] = '5';
        cout << Sum() << ' ' ;
        // Thay 5 thành 6 --> max
        for(int i=0 ; i<a.size() ; i++)
            if(a[i]=='5') a[i]='6' ;
        for(int i=0;i<b.size();i++)
            if(b[i]=='5') b[i] = '6';
        cout << Sum() << ' ' ;
    }
}