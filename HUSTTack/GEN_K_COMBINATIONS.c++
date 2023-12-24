// Tổ hợp chập k của n
#include<bits/stdc++.h>
using namespace std;
    int n,k;

int th[100];
bool chuaxet[100] ;

void Try(int i){
    for(int j= th[i-1]+1; j<=n-k+i;j++){
        if(!chuaxet[j]){
            th[i] = j ;
            chuaxet[j] = true ;
            if(i==k){
                for(int l=1 ; l<=k ;l++)
                    cout << th[l] << ' ' ;
                    cout << "\n";
                }
            else Try(i+1) ;
            chuaxet[j]= false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n ;
    th[0] = 0;
    Try(1) ;
    return 0;

}