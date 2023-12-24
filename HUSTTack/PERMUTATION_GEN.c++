// Sinh hoán vị ko trùng
#include<bits/stdc++.h>
using namespace std;
int n ;
int hv[100];
bool chuaxet[100] ;
void Try(int i){
    for(int j =1 ; j<=n;j++){
    if(!chuaxet[j]){
        hv[i]= j;
        chuaxet[j]=true ;
        if(i==n){
            for(int l=1 ; l<=n; l++){
                cout << hv[l];
                cout << ' ' ;
            }
            cout << "\n" ;
        }
        else Try(i+1) ;
        chuaxet[j] = false; 
    }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try(1) ;
}