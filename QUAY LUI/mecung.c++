// Mê cung được tạo bởi một ma trận nhị phân A[N][N].
// Một con chuột đi từ ô đầu tiên góc trái A[0][0] đến ô cùng góc phải A[N-1][N-1]
// theo nguyên tắc  + DOWN (đi xuống nếu ô đó là 1 ) ; + RIGHT (R) sang phải nếu ô đó có giá trị 1
// Đưa ra -1 nếu ko tới được đích

// Nhập t bộ test, n ( kích thuocs mê cung) và nhập mê cung
// Đưa ra cách đi : DRDDR ( xuống phải xuống xuống phải) ( in ra theo thứ tự từ điển)

#include<bits/stdc++.h>
using namespace std;
int n, a[100][100];
vector<string> res;   // Xây vecto để dễ sort và in ra kết qả vì kết quả phải in theo thứ tự từ điển
bool check=false;
void init() {
    cin >> n;
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j] ;
        }
    }
    res.clear();
    check=false;
}


void Try(int i, int j , string s) { 
    if(i==1 && j==1 && a[i][j]==0){    // check xem ô đầu tiên có đi được hay không
        check = false ; 
        return;
    }
    if(i==n && j==n ){       // Check ô cuối cùng có đi được hay không
        res.push_back(s) ;             // Đưa kết quả vào s
        check = true ;
        return;
    }
    if(i<n && a[i+1][j]){    // Đi xuống dưới ( cộng thêm 1 cột)
        Try(i+1,j,s+'D');
    }
    if(j<n && a[i][j+1]){    // Đi xuống dưới ( cộng thêm 1 cột)
        Try(i,j+1,s+'R');
    }
    // if((i<n && j<n && !a[i+1][j] && !a[i][j+1]) || i >n || j>n) // (i,j<n nhưng a khác 0,1 thì false ) và (i,j >n thì false)
    //     return ;

}


int main() {
    int t;
    cin >> t;
    while(t--) {
        init();
        Try(1,1, "");
        if (!check)          // không có cái nào thì in ra -1  (check=false)
            cout << -1;
        else {
            sort(res.begin(), res.end());
            for(int i = 0; i < res.size(); i++)
                cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
