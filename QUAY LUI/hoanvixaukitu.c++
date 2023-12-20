// Hoán vị sâu kí tự S. Ví dụ S="ABC" ta có kết quả {ABC ACB BAC BCA CAB CBA}
// Nhập vào số bộ test t 
// Mỗi dòng nhập 1 sâu kí tự 

#include<bits/stdc++.h>
using namespace std;
string s;
int a[100];   // Lưu vị trí kí tự
bool chuaxet[100];
void Try(int i){
    for(int j=0; j <s.size(); j++){
        if(!chuaxet[j]){
            a[i] = j ;
            chuaxet[j] = true ;
            if(i == s.size()){
                for(int l=1; l<=s.size(); l++){
                    cout << s[a[l]] ;            // Vì xuất ra s[a[l]] - a[l] đã đổi vị trí các kí tự
                }
                cout << " " ;
            }
            else Try(i+1);
            chuaxet[j] =false ;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >>t;
    while(t--){
        cin >>s ;
        memset(chuaxet,false,sizeof(chuaxet));
        sort(s.begin(),s.end());
        Try(1);
        cout << '\n';  
    }
    return 0;
}