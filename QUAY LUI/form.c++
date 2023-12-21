#include<bits/stdc++.h>
using namespace std;


// Sinh xâu nhị phân
// int np[100], n=4;
// void Try(int i){
//     for(int j=0; j<=1; j++){
//         np[i] = j ;
//         if(i ==n){
//             for(int l=1;l<=n;l++){  // Dòng 9 - 12 có thể thay đổi nội dung
//                 cout << np[l];
//             }
//             cout << " " ;           //
//         }
//         else Try(i+1) ; 
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     for(int i=1;i<=n;i++){
//         np[i]=0;
//     }
//     Try(1);                  
//     return 0 ;
// }


// Sinh hoán vị 
// int hv[100], n= 4 ;
// bool chuaxet[100] ;
// void Try(int i){
//     for(int j =1 ; j<=n;j++){
//         hv[i]= j;
//         chuaxet[j]=true ;
//         if(i==n){
//             for(int l=1 ; l<=n; l++){
//                 cout << hv[l];
//             }
//             cout << " " ;
//         }
//         else Try(i+1) ;
//         chuaxet[j] = false; 
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     Try(1) ;
// }


// Sinh tổ hợp chập k
int th[100] , k=4 , n=6 ;
bool chuaxet[100] ;
void Try(int i){
    for(int j= th[i-1]+1; j<=n-k+i;j++){
        if(!chuaxet[j]){
            th[i] = j ;
            chuaxet[j] = true ;
            if(i==k){
                for(int l=1 ; l<=k ;l++)
                    cout << th[l] ;
                    cout << " ";
                }
            else Try(i+1) ;
            chuaxet[j]= false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    th[0] = 0;
    Try(1) ;
    return 0;

}