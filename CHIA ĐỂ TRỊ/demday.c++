// Nhập vào n tính số dãy số có tổng bằng n
// Số dãy là 2^(n-1)
// Sau đó chia dư cho 123456789
 #include<bits/stdc++.h>
using namespace std ;
long long const mod = 123456789 ;
long long Mul(int n){
    if(n==0) return 1 % mod ;
    if(n==1) return 2 % mod ;
    long long p = Mul(n/2);
    if(n%2 == 1 ) return 2*p*p % mod ;
    return p * p % mod ;
}

int main(){
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        n--;  //tính n-1 --> tính 2^(n-1)
        cout << Mul(n) << "\n" ;
    }
    return 0 ;
}