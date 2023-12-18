// Một dãy kí tự G gồm các chữ cái A,B ( G[1]=A , G[2]=B , G[n]= G[n-2]+G[n-1]) - cứ cộng chuỗi vào
// Tìm kí tự thứ i của dãy fibonaci thứ n
// https://www.youtube.com/watch?v=k8OTyO46tbQ&list=PL8JRkLx_73-Ik1qjQQb4p2_VsH8bW4oul&index=13

#include<bits/stdc++.h>
using namespace std ;

long long F[93] ;

void Solve(){
    long long n ,i ;
    cin  >> n >> i ;
    while (n>2){
        if( i <= F[n-2])  n-=2 ;
        else{
            i -= F[n-2] ;
            n -= 1 ;
        } 
    }
    if(n==1) cout << 'A' ;
    else cout << 'B' ;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    F[1] = F[2] = 1 ;
    for(int i = 3 ; i<=92; i++){
        F[i] = F[i-2] + F[i-1];
    }
    int t;
    cin >> t ;
    while(t--) Solve();
    return 0;
}