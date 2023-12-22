// Tìm xâu con đối xứng dài nhất
// Ví dụ abbcaac ( kết quả ra 4 - vì sâu caac đối xứng)
// Nhập vào sâu s
// Output : xâu đối xứng dài nhất

#include <bits/stdc++.h>
using namespace std ;

int main(){
    string s;
    cin >> s;
    int n= s.size();
    s = 'x'+s ; 

    // F[i][j] = F[i+1][j-1] && (s[i]==s[j])
    bool F[n+1][n+1] ;
    memset(F,false,sizeof(F));
    for(int i=1 ;i<=n;i++) F[i][i] =true ; // Xâu con có độ dài bằng 1
    // Xét các xâu con có độ dài từ 2 cho n
    int ans =1 ;
    for(int len =2 ; len <=n ; len++){
        for(int i=1;i<=n-len+1;i++){
            int j = i + len -1 ; 
            // F[i][j] có độ dài len
            if(len==2 && s[i]==s[j]) F[i][j] =true;     // trường hợp đặc biệt vì ko có xâu ở giữa
            else{
                F[i][j] = F[i+1][j-1] && (s[i] == s[j]) ;
            }
            if(F[i][j])  ans = max(ans,len);
        }
    }
    // In ra bảng đếm len
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << F[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
    cout << ans << endl ;
}
