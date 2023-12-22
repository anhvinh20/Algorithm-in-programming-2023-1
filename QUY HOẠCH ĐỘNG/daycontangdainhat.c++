// Nhập n phần tử
// Nhập vào phần tử của mảng A
// In ra độ dài dãy con tăng dài nhất

#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // L[i] : độ dài của dãy con tăng dài nhất kết thúc ở chỉ số i
    // L[i] = max(L[i],L[j]+1) : a[i]>a[j]
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i] ;
    vector<int> L(n,1) ;
    for(int i=0; i<n;i++){
        //L[i]: L[j] : duyệt qua từng phần tử đứng trước chỉ số i
        for(int j=0;j<i;j++){
            if(a[i] > a[j]){
                L[i] = max(L[i], L[j]+1) ; // Cập nhập i là phần tử lớn nhất và dãy có dộ dài max
            }
        }
    }
    cout << *max_element(L.begin(), L.end()) << endl ;
}