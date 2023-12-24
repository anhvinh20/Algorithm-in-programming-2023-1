#include<bits/stdc++.h>
using namespace std;
// Sinh xâu nhị phân theo thứ tự từ điển
int n;
int np[100];
void Try(int i){
    for(int j=0; j<=1; j++){
        np[i] = j ;
        if(i ==n){
            for(int l=1;l<=n;l++){  // Dòng 9 - 12 có thể thay đổi nội dung
                cout << np[l];
            }
            cout << "\n" ;          
        }
        else Try(i+1) ; 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++){
        np[i]=0;
    }
    Try(1);                  
    return 0 ;
}