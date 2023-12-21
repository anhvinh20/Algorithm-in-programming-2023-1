// Mặc định bàn cờ là 8*8 
// Đặt 8 con hậu vào sao cho không có 2 con nào ăn nhau, tihs số điểm đạt được cao nhất
// Mỗi test gồm 8 dòng, mỗi dòng gồm 8 số nguyên mô tả bản đồ :   1 2 3 4 5 6 7 8
//                                                                9 10 11 12 13 14 15 16 ..... ( 8 dòng )
// Output : Ghi ra số điểm lớn nhất đạt được


#include<bits/stdc++.h>
using namespace std;

bool h[11], c[11], nguoc[22], xuoi[22] ;
int n , res;
int a[11];           // vị trí đặt quân hậu
int val[10][10];     // Giá trị
void init(){
    for(int i=1;i<=8;i++){
        for(int j=1 ; j<=8; j++){
            cin >> val[i][j];
        }
    }
    n=8;
    for(int i=0;i<11;i++)
        h[i] =c[i] = false;
    for(int i=0;i<22;i++)
        nguoc[i]=xuoi[i]=false;
    res=0;
}
void Try(int i)
{
    for(int j =1; j<=n; j++){
        if(!h[j]&&!c[j] && !nguoc[i+j-1] && !xuoi[i-j+n]){    
            a[i] = j ;         // vị trí đặt quân hậu thứ i tại hàng i cột j
            h[j] = c[j] = nguoc[i+j-1] = xuoi[i-j+n] = true ; // Gán nó là đã đi qua 
            if(i==n){         // Thì cộng thêm res thôi          
                int ans = 0 ;
                for(int l=1;l<=8; l++)
                    ans+= val[l][a[l]];     // Cộng tổng điểm lại
                res= max(res,ans);
            }
            else Try(i+1) ;
            h[j] = c[j] = nguoc[i+j-1] = xuoi[i-j+n] = false ;  // Trả lại là false nếu chưa đi qua
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        Try(1);
        cout << res << "\n";
    }
    return 0 ; 
}