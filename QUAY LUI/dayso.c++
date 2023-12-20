//Nhập vào số bộ test
// Nhập dãy số n :                                 [1,2,3,4,5] 
// In ra các hàng sau là tổng 2 chữ số hàng trên : [3,5,7,9]
//                                                 [8,12,16]
//                                                 [20,28]
//                                                 [48]


#include<bits/stdc++.h>
using namespace std;

void Solve(){
    int n ; 
    cin >> n;
    int a[n+5][n+5];
    for (int j=1 ; j <= n ; j++){
        cin >> a[1][j] ;      // Nhập dãy số
    }  
    int cot=n-1 ;
// QUan trọng 
    for(int i =2 ; i<=n; i++){
        for(int j=1 ; j<=cot; j++)
            a[i][j] = a[i-1][j] + a[i-1][j+1] ;
            cot-- ;
    }
// In ra 
    cot = n ;
    for(int i = 1 ; i<=n ; i++){
        cout << '[' ;
        for(int j=1; j<cot; j++)
            cout << a[i][j] << ' ' ;       // in ra số
            cout << a[i][cot] << ']' ;     // cot la điểm dừng để in ra dấu ]
            cot--;
            cout <<'\n' ;
    } 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t ;
    cin >> t ;
    while (t--)
    {
        Solve();
    }
    return 0 ;
}