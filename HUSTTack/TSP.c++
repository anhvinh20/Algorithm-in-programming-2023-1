// Cho n thành phố vào chi phí đi lại giwuax các thành phố c[n][n]
// Chi phí đi lại giwuax thành phố i với chính nó là 0 
// In ra chi phí ít nhất maf người đó muốn thăm tất cả các thành phố


#include <bits/stdc++.h>
using namespace std ;
#define MAX 20

int n ;
int c[MAX][MAX];
int visited[MAX];
int x[MAX] ;
int c_min = INT_MAX;
int f_min = INT_MAX;
int f = 0 ;

void Try(int k){
    for(int v = 1 ; v < n ; v++ ){
        if(!visited[v]){
            visited[v] = true ;   // đánh dấu là đã đi
            x[k] = v ;            // thêm vào lộ trình
            f += c[x[k-1]][v];    // Cộng chi phí
            if( k == n -1 ){      // Nếu đi đến cuối thì cộng thêm từ điểm cuối đến điểm đầu rồi so sánh
                f_min = min(f_min , f+c[x[k]][0]);
            }else{             // Nhánh cận nếu vẫn nhỏ hơn chi phí min thì tiếp tục ( cmin là chi phí ước lượng)
                if(f+(n-k)*c_min <= f_min)  Try(k+1);
            }
            f -= c[x[k-1]][v];       // trả lại nếu ko đi
            visited[v] = false ;
        }
    }
}

int main(){
    cin >> n ;
    for( int i=0; i<n ;i++){
        visited[i] = false; 
        for(int j=0; j<n ;j++){
            cin >> c[i][j] ;
            c_min = min(c_min, c[i][j]);
        }
    }
    x[0] = 0;
    Try(1);
    cout << f_min;
    return 0;
}

