// Bài toán đổi tiền sử dụng tham lam
// Đổi tiền ra các mệnh giá tương ứng a[10] ={1000,500,200,...}
// NHập số lượng bộ test, nhập số tiền
// Output : số tờ tiền min 

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; // só lượng bộ test
    cin >> t; 
    for(int i =1 ;i<=t ;i++){
        int n;
        cin >> n;
        int a[10] = {1000,500,200,100,50,20,10,5,2,1}; // Tiền
        int cnt = 0 ; // Đếm số lượng tờ tiền
        for(int i=0;i<10;i++){
            cnt += n/a[i] ;
            n %= a[i];
        }
        cout << cnt ;
    }
}