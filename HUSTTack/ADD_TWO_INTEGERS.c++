// Tính tổng 2 số 
#include<bits/stdc++.h>
using namespace std ;
int main(){
    string a,b ;
    cin >> a >> b ;    
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
    cout << res;
    return 0;
}