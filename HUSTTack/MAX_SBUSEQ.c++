// Tổng dãy con lớn nhất ( sử dụng chia để trị )
// Nhập vào n số phần tử của dãy, nhập vào mảng a[i]

#include <bits/stdc++.h> 
using namespace std;
#define MAX 10000000
int a[MAX] ;
int n ;

int maxLeftMid(int i,int j){
    int s = a[j] ;
    int maxLM = 0 ;
    for(int k=j-1 ; k>=i ; k--){
        s += a[k];
        maxLM = max(maxLM,s);
    }
    return maxLM ;
}

int maxRightMid(int i,int j){
    int s = a[i] ;
    int maxRM =0 ;
    for(int k=i+1 ; k<=j ; k++){
        s +=a[k];
        maxRM = max(maxRM,s);
    }
    return maxRM ;
}
int SubSeqMax(int i, int j){
    if(i==j)  return a[i] ;
    // Chia 2 dãy con ra thành 2 dãy nhỏ
    int mid = (i+j)/2 ;
    int wL= SubSeqMax(i,mid);
    int wR= SubSeqMax(mid+1, j);

    int maxLM = maxLeftMid(i,mid);
    int maxRM = maxRightMid(mid+1,j);
    int wM = maxLM + maxRM ;
    return max(max(wR,wM), wL);
}

int main(){
        cin >> n;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        cout << SubSeqMax(0,n-1) << endl ;   
}