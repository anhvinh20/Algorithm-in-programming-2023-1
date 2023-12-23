// Mua sách sao cho giá rẻ nhất, cứ mua 3 cuốn được free 1 cuốn rẻ nhất
//Nhập vào n cuốn sách, mảng giá tiền
// Ví dụ : 1 3 5 2 2 6 5
// Kết quả : 21

#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int ans = 0 ;
int main(){
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> a[i] ;
    }
    sort(a+1,a+1+n, greater<int>());  // sắp xếp giảm dần thì thêm greater<int>() vào
    for(int i=1 ; i<=n ; i++){
        // cout << a[i] << " " ;   // in mảng
        if(i%3 == 0){ // Bỏ qua chỗ sách chia hết cho 3
            continue;
        }
        ans += a[i];
    }
    cout << ans ;
}