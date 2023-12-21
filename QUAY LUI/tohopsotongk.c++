// Nhập vào t bộ test, n ( số phần tử của mảng ) , k ( tổng )
// VD : Nhập vào n=4 , k =8 ( 2 4 6 8 ) --> OUT : [2 2 2 2] [2 2 4]  [2 6] [4 4]

#include<bits/stdc++.h>
using namespace std;
int n,k ;
int a[100] ;
vector< vector<int> > res;

void Try(int i,int sum, vector<int> v){
    if(sum >k ) return ;
    if(sum == k){
        res.push_back(v);   // nếu sum == k thì đưa vào kết quả để in
        return ;
    }
    for(int j=i; j<=n;j++){
        if(sum+a[j]<=k){
            v.push_back(a[j]);     // a[j] vào v
            Try(j,sum+a[j],v);     // Phải gọi j vì output có thể lặp lại
            v.pop_back();          // Đưa a[j] ra khỏi
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; 
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++)
            cin >> a[i] ;
        sort(a+1,a+n+1);

        vector<int> v ;
        v.clear();
        res.clear();
        Try(1,0,v);
        if(res.size()==0){
            cout << -1 << endl;
            continue;
        }
        for(int i =0; i <res.size(); i++ ){            // in theo đề bài
            cout << '[' ;
            for(int j=0; j<res[i].size()-1;j++)
                cout << res[i][j] << ' ';
                cout << res[i][res[i].size()-1] << "]" ;
                cout << " ";
            }
            cout << "\n";
        
    }
    return 0 ;
}