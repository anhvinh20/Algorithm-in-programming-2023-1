// Dãy an. Tìm các dãy con chẵn nếu tổng các phần tử là chẵn - số lượng Q
//out put ghi ra giá trị Q mod 1e9+7

#include<bits/stdc++.h>
using namespace std;
int n,m,w[100],a[100],res=0;
int Try(int n,int m){
    
}
int main(){
   
    int res1 =0,tong=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        tong+=a[i];
        if(tong%2==0){
            res1++;
        }
    }
    res+=res1;
    for(int i=1;i<n;i++){
        if(a[i-1]%2==0){
            res+=res1-1;
            res1=res1-1;
        }
        else{
            res+=n-i-res1;
        res1=n-i-res1;
        }

    }

   cout<< res;
    return 0;
}