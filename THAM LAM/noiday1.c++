// Nối sợi dây. Cho n sợi dây với độ dài khác nhau trong mảng A
// Nối sợi dây sao cho chi phí nhỏ nhất ( chi phí nối dây là tổng độ dài sợi A[i]+A[j])
//Nhập t bộ test , nhập n , mảng A
// Đầu ra : chi phí



#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t ;
    while(t--){
        int n ;
        long long val ;
        // Sử dụng hàng đợi uwuu tiên ( phần tử đầu luôn là lớn nhất )
        priority_queue<long long, vector<long long>, greater<long long> > a;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> val ;
            a.push(val);   // đưa giá trị dây vào hàng đợi
        }
        long long res = 0 ;   // chi phí
        while(a.size()>1){
            long long x = a.top() ; a.pop() ;   // top trả về phần tử cao nhất, pop lấy ra
            long long y = a.top() ; a.pop() ;
            a.push(x+y) ;
            res += x+y ;
        }
        cout << res << '\n' ;
    }
}