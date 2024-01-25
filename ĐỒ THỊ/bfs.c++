#include <bits/stdc++.h>
using namespace std;

// 10 11
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9 
// 6 7
// 5 8
// 8 9

// Danh sách cạnh

int n, m ;
vector<int> adj[1000] ;
bool visited[1000] ;

void inp(){
    cin >> n >> m ;
    for(int i= 0 ; i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y) ;   // chuyển thành danh sách kề
        adj[y].push_back(x) ;   // có huongs thì bỏ cái này
    }
    memset(visited,false,sizeof(visited)) ;   /// khởi tạo visted 
}

void bfs(int u){
    queue<int> q ;
    q.push(u) ;
    visited[u] = true; 
    // Buoc lap
    while(!q.empty()){
        int v = q.front() ;
        q.pop() ;
        cout << v << " " ;
        for(int x : adj[v]){
            if(!visited[x]){
                q.push(x) ;
                visited[x] = true ;
            }
        }
    }
}
int main(){
    inp();
    bfs(1) ;
    return 0 ;
}