// CHo danh sách cạnh --> danh sách kề

#include <bits/stdc++.h>
using namespace std ;

int n,m ;
vector<int> adj[1000] ;
vector<pair<int,int>> edge ;
int a[1000][1000] ;
int main(){
    cin >> n >> m ;
    for(int i =0 ; i<m; i++){
        int x,y ; 
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    for(int i =1 ; i<= n ; i++){
        cout << i << " : " ;
        for(int x : adj[i]){
            cout << x << " " ;
        }
        cout << " \n " ;
    }
}

// danh sách kề sang danh sách cạnh
// Cho n đỉnh và string
// 5 
// 2 3 4      (danh sách kề của đỉnh 1)
// 1 3 4 5    ( cta phải tách string )
// 1 2 4 5    
// 1 2 3 5
// 2 3 4 
int main(){
    cin >> n ;
    cin.ignore() ;
    for(int i =1 ; i<= n; i++ ){
        string s, num ;
        getline(cin ,s ) ;
        stringstream ss(s) ;
        while (ss >> num){
            if(stoi(num) > i){
                edge.push_back({i,stoi(num)});
            }
        } 
    } 
    for(int i= 1;i<=n ;i++){
        for(int j=1 ;j<=n ; j++){
            cout << a[i][j] << " " ;
        }
        cout << endl;
    }
}