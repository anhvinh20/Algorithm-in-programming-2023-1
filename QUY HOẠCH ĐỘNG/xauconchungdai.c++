//LCS ( Longest common subsequence )
// Nhập vào 2 xâu X,Y

#include <bits/stdc++.h>
using namespace std ;
int main(){
    string X,Y; 
    cin >> X >> Y;
    int n =X.size() , m =Y.size() ;
    int F[n+1][m+1] ;
    for(int i=0; i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){  // Nếu ko nhập gì thì trả 0 luôn
                F[i][j] =0;
            }
            else{ // Thuật toán 
                if(X[i-1] == Y[j-1]){  
                    F[i][j] = F[i-1][j-1] +1 ; 
                }else{
                    F[i][j] = max(F[i-1][j] , F[i][j-1]) ;
                }
            }
        }

    }
    cout << F[n][m] << endl;
}