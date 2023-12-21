// Bàn cờ kích thước n*n , qquaan hậu có thể đi ngang dọc, chéo
// Có n quân hậu , đếm cách đặt n quân hậu lên bàn cờ sao cho vs 2 quân bất kì chúng ko ăn nhau
// Input : n 
// Output : Số cách đặt hậu
// https://www.youtube.com/watch?v=4wWL577cH94&list=PL8JRkLx_73-Irb5EYkB_11O8iL0vYa_Qk&index=14

#include<bits/stdc++.h>
using namespace std;

bool h[11], c[11], nguoc[22], xuoi[22] ;
int n , res;

void Try(int i)
{
    for(int j =1; j<=n; j++){
        if(!h[j]&&!c[j] && !nguoc[i+j-1] && !xuoi[i-j+n]){    // nguoc voi xuoi la đường chéo mà khi đặt con hậu có thể đi [i+j-1] ... là cách đánh dấu xem video
            h[j] = c[j] = nguoc[i+j-1] = xuoi[i-j+n] = true ; // Gán nó là đã đi qua 
            if(i==n)         // Thì cộng thêm res thôi          
                res++;
            else Try(i+1) ;
            h[j] = c[j] = nguoc[i+j-1] = xuoi[i-j+n] = false ;  // Trả lại là false nếu chưa đi qua
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try(1);
    cout << res << "\n";
    return 0 ; 
}