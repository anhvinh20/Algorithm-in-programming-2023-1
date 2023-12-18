// Một con kaguru có chieuef cao X chưa dc 1 con có chiều cao Y ( sao cho X>= 2Y)
// Nhập vào t số bộ test
// Nhập N số con kanguru, con thứ i có chiều cao A[i]
// Tính số con kanguru nhìn thấy trong vườn thú là ít nhất
// https://www.youtube.com/watch?v=O2JlCzpKx6s&list=PL8JRkLx_73-Ik1qjQQb4p2_VsH8bW4oul&index=11
#include<bits/stdc++.h>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int res = n ;
        for(int i =0; i<n;i++){
            cin >> a[i] ;
        }
        sort(a.begin(),a.end());
        for(int i=n/2-1 , j =n-1 ; i>=0, j>=n/2 ; )
        {
            if(a[j]>=2*a[i]){
                res= res-1;
                i--;
                j--;
            }
            else i--;
        }
        cout << res+1 << "\n" ;
    }
    return 0;
}