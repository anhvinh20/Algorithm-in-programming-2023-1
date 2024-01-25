// Cho ma trận kề in ra danh sách kề

// danh sách kề : ví dụ
// 1: 2, 3 ,4
// 2 : 1, 5 ,6 

#include <bits/stdc++.h>
using namespace std ;

int n,m ;
vector<pair<int,int>> edge ;
int a[1000][1000] ;

int main(){
    cin >> n  ;
    for(int i =0 ; i<=n; i++){
        for(int j =1 ; j<=n; j++){
            cin >> a[i][j] ;
        }
    }
    for(int i =1 ; i<= n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(a[i][j] && i < j ){
                edge.push_back({i,j}) ; 
            }
        }
    }

    for( auto it : edge ){
        cout << it.first << " " << it.second << endl ;
    }
}


// ma trận kề ra danh sách cạnh 
// int n,m ;
// int a[1000][1000] ;
// vector<int> adj[1001] ;
// int main(){
//     cin >> n  ;
//     for(int i =0 ; i<=n; i++){
//         for(int j =1 ; j<=n; j++){
//             cin >> a[i][j] ;
//         }
//     }
//     for(int i =1 ; i<= n ; i++){
//         for(int j=1 ; j<=n ; j++){
//             if(a[i][j] ){
//                 adj[i].push_back(j); 
//             }
//         }
//     }

//     for( int i=1;i<= n ; i++ ){
//         cout << i << " : " ;
//         for(int x : adj[i]){
//             cout << x << " " ;
//         }
//         cout << endl ;
//     }
// }