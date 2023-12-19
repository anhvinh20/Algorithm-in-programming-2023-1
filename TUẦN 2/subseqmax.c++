// Tổng dãy con lớn nhất 
// Nhập vào n số phần tử của dãy, nhập vào mảng a[i]
#include <bits/stdc++.h> 
using namespace std;
    int a[1000] ;



int maxLeftMid(int i,int j){
    int maxLM = a[j] ;
    int s =0 ;
    for(int k=j-1 ; k>=i ; k--){
        s +=a[k];
        maxLM = max(maxLM,s);
    }
    return maxLM ;
}

int maxRightMid(int i,int j){
    int maxRM = a[j] ;
    int s =0 ;
    for(int k=i+1 ; k<=j ; k++){
        s +=a[k];
        maxRM = max(maxRM,s);
    }
    return maxRM ;
}
int SubSeqMax(int i, int j){
    if(i==j)  return a[i] ;
    int mid = (i+j)/2 ;
    int wL= SubSeqMax(i,mid);
    int wR= SubSeqMax(mid+1, j);

    int maxLM = maxLeftMid(i,mid);
    int maxRM = maxRightMid(mid+1,j);
    int wM = maxLM + maxRM ;
    return max(max(wL,wR), wM);
}

int main(){
        int n ;
        cin >> n;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        cout << "\n";
        cout << "Max: " << SubSeqMax(0,n-1) << endl ; 

    
}