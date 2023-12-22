// Bài toán cái túi quy hoạch đôngj
// Chọn trọng lượng đồ vật ( <= trọng lượng tối đa ) sao cho giá trị max
// Nhập vào n : số lượng túi , S trọng lượng tối đa
// Nhập w[i] - trọng lượng , v[i] - giá trị
// Output : Tổng giá trị đựng được
#include <bits/stdc++.h>
using namespace std ;
int main(){
    int n, S ;
    cin >> n >> S ;
    int w[n+1] , v[n+1] ;
    for(int i=1 ; i<=n ;i++) cin >> w[i] ;
    for(int i=1; i<=n ; i++) cin >> v[i] ;
    int dp[n+1][S+1] ;   // Giá trị đồ vật khi max trọng lượng túi
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=S;j++){
            // Không lựa chọn đồ vật thứ i vào trong túi
            dp[i][j] = dp[i-1][j];
            if( j >= w[i]){
                // Có thể đưa đồ vật thứ i vào trong túi
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]) ; // Thuật toán
            }
        }
    }
    // Cách lấy túi
    // for(int i=1; i<=n ; i++){ 
    //     for(int j=1 ; j<=S ; j++){  
    //         cout << dp[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
    cout << dp[n][S] << endl;
}