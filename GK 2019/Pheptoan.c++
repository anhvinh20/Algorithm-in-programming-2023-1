//Cho dãy số nguyên n và số nguyên b.
// Điền dấu + hoặc - giwuax 2 số canchj nhau để thu dc biểu thức =b 
// Nhập n,b. dãy số
// Output : Lời giải
#include<bits/stdc++.h>
using namespace std;
int n, bMark[51][20001],b,a[50];
int Try(int k,int m){
    if(k==1){
        if(a[0]==m){
            return 1;
        }
        return 0;
    }
    if(bMark[k][m]!=-1){
        return bMark[k][m];
    } 
   int res=Try(k-1,m+a[k-1])+Try(k-1,m-a[k-1]);  
   bMark[k][m]=res;
    return res;
}
int main(){
    memset(bMark,-1,sizeof(bMark));
    cin >>n>>b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
    cout<<Try(n,b)<<endl;
return 0;
}