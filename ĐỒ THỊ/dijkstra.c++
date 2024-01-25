// Cho dnah sách cạnh có trọng số
// 6 đỉnh, 8 cạnh, xuất phát 1
// 6 8 1 6        
// 1 2 7 
// 1 3 12
// 2 3 2
// 2 4 9
// 3 5 10
// 4 6 1
// 5 4 4
// 5 6 5

#include <bits/stdc++.h>
using namespace std ;

using ll= long long ;
const int maxn = 10001 ;
int n , m , s , t ; //  s để lấy đỉnh đầu tiên đi , t là đỉnh cuối
vector<pair<int,int>> adj[maxn] ;

void nhap(){
    cin >> n >> m >> s >> t;
    for(int i =0 ; i<m; i++){
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w}) ;
        adj[y].push_back({x,w}) ;   // có huwogns thì bỏ
    }
}

const int INF = 1e9 ;
int pre[maxn];

void dijkstra(int s, int t){ // t in ra đường đi ngắn nhất
    // Mang luu khoang cach duong đi
    vector<ll> d(n+1 , INF);
    pre[s] =s ;
    d[s] = 0 ;
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> Q ;
    // {khoang cach, dinh}
    Q.push({0,s}) ;
    while(!Q.empty()){
        // Chọn ra đỉnh có khoảng cách từ s nhỏ nhất
        pair<int,int> top = Q.top() ; Q.pop();
        int u = top.second ;
        int kc = top.first;
        if(kc > d[u]) continue ;
        // Relaxation : Cập nhập khoảng cách từ s cho tới mọi đỉnh kề với u
        for(auto it : adj[u]){
            int v = it.first ;
            int w = it.second ; 
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v}) ;
                pre[v] = u ;
            }
        } 
    }
    cout << d[t] << endl;
    vector<int> path ;
    while(1){
        path.push_back(t) ;
        if(t==s) break ;
        t = pre[t];
    }
    reverse(begin(path), end(path));
    for(int x: path){
        cout << x << ' ';
    }
    


    // for(int i =1 ; i <=n ; i++){
    //     cout << d[i] << ' ' ;
    // }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nhap();
	dijkstra(s,t);
}