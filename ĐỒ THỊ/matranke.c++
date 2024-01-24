// Cho danh sách cạnh, in ra ma trận kề
 // Cho đồ thị vô hướng
// Input : dòng đầu chứa 2 số n,m là số đỉnh và số cạnh
// m dòng tiếp theo mỗi dòng là số u,v biểu diễn cạnh u,v 
// của đồ thị. Các cạnh được liệt kê theo thứ tự tăng dần
// Output in ra ma trận kề

#include <bits/stdc++.h>
using namespace std ;

int n,m;
int a[1000][1000] ;

int main(){
    cin >> n >> m ;
    for(int i=0; i <m; i++){
        int x,y ; 
        cin >> x >> y ;
        a[x][y] = a[y][x]  = 1 ;
    }
    for( int i =1 ; i<=n ; i++){
        for(int j=1; j<=n ; j++){
            cout << a[i][j] << " " ;
        }
        cout << endl ;
    }
}


// dadnh sách kề ra ma trận kề 
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
            a[i][stoi(num)] = 1;
        } 
    } 
    for(int i= 1;i<=n ;i++){
        for(int j=1 ;j<=n ; j++){
            cout << a[i][j] << " " ;
        }
        cout << endl;
    }
}