//Nhập t là số lượng bộ test
// N-1 là số phép tính , K là số thứ K trong dãy
// Ví dụ [1] --> [1,2,1] --> [1,2,1,3,1,2,1]
// Dãy số có dang A --> A,x,A (với x là số bé nhất chưa xuất hiện trong dãy)
// Độ dài dãy 2^(N-1)
#include<bits/stdc++.h>
using namespace std ;
long long Mul(int n){
    if(n==0) return 1 ;
    if(n==1) return 2 ;
    long long p = Mul(n/2);
    if(n%2 == 1 ) return 2*p*p ;
    return p * p ;
}

int main(){
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        long long k;
        cin >> n >> k ;
        long long len = Mul(n)/2 ;
        while(1){
            if(n==1){
                cout << 1; 
                break;
            }
            if(len == k){
                cout << n;
                break;
            }
            if(k > len ){
                k = len - (k-len);
            }
            n--;
            len/=2;
        }
    cout << "\n";
    }
    return 0 ;
}

