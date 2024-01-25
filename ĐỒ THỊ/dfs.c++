#include <bits/stdc++.h>
using namespace std ;
// DFS cho vô hướng
// Input 
// 9 9 
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8 
// 8 9


int n , m ;
vector<int> adj[1000] ;
bool visited[1000] ;

void inp(){
    cin >> n >> m ;
    for(int i= 0 ; i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;   // có huongs thì bỏ cái này
    }
    memset(visited,false,sizeof(visited)) ;   /// khởi tạo visted 
}

void dfs(int u){
    cout << u << " " ;
    // Danh dau da duoc tham
    visited[u] = true ;
    for(int v : adj[u]){
        // Neu dinh v chua duoc tham
        if(!visited[v]){
            dfs(v) ;
        }
    }
}

int main(){
    inp() ; 
    dfs(1) ;
}