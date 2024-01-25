


#include<bits/stdc++.h>
using namespace std;

int rows, cols;
long long maxSum = 0;
long long grid[1002][1002];
bool visited[1002][1002];
int dx[] = {1, 0, 1}; // Change in x-coordinate (down, right, diagonal)
int dy[] = {0, 1, 1}; // Change in y-coordinate (down, right, diagonal)
char directions[] = {'D', 'R', 'C'}; // D for Down, R for Right, C for Diagonal
string path = "", bestPath = "";

// Backtracking function to find the path with the maximum sum
void findMaxPath(int x, int y, long long currentSum){
    // Base case: Reached bottom-right corner
    if(x == rows - 1 && y == cols - 1){
        if(currentSum > maxSum){
            maxSum = currentSum;
            bestPath = path;
        }
        return;
    }

    // Exploring the three possible directions: down, right, diagonal
    for(int i = 0; i < 3; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // Check if the next position is within bounds and not visited
        if(nextX < rows && nextY < cols && grid[nextX][nextY] != 0 && !visited[nextX][nextY]){
            visited[nextX][nextY] = true;
            currentSum += grid[nextX][nextY];
            path.push_back(directions[i]);

            // Recursive call
            findMaxPath(nextX, nextY, currentSum);

            // Backtracking
            path.pop_back();
            currentSum -= grid[nextX][nextY];
            visited[nextX][nextY] = false;
        }
    }
}


int main(){
    memset(visited, false, sizeof(visited));
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
    }

    // Starting the path with the initial cell's value
    findMaxPath(0, 0, grid[0][0]);

    // Output the result
    if(maxSum > 0){
        cout << maxSum << " " << bestPath;
    }
    else{
        cout << -1;
    }

    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// int n,m;
// long long res = 0;
// long long a[1002][1002];
// bool b[1002][1002];
// int p[]={1,0,1};
// int z[]={0,1,1};
// char t[]={'R','D','C'};
// string s="",road="";
// void Try(int x,int y,long long tong){
//     if(x==n-1&&y==m-1){
//         // tong+=a[n-1][n-1];
//         if(tong>res){
//             res=tong;
//             road=s;
//         }
        
            
//          return;
//     }
   
//    for(int i=0;i<3;i++){
    
//     if(x+z[i]<n && y+p[i]<m  && b[x+z[i]][p[i]+y]==false){
//         b[x+z[i]][p[i]+y]=true;
//         tong+= a[x+z[i]][p[i]+y];
//         s.push_back(t[i]);
//         Try(x+z[i],y+p[i],tong);
//         s.pop_back();
//         tong -=a[x+z[i]][p[i]+y];
//         b[x+z[i]][p[i]+y]=false;
        
//     }
//    }
   
//    return;
// }
// int main(){
//     int x1,y1,z1;
//     memset(b,false,sizeof(b));
//     memset(a,0,sizeof(a));
//     cin>>n;
//     int n1=0;
//     m=0;
//     // for(int i=0;i<n;i++){
//     //     for(int j=0; j<m;j++)
//     //     cin>> a[i][j];
//     // }
//     for (int i = 0; i < n; i++){
//         cin>>x1>>y1>>z1;
//         a[x1-1][y1-1]=z1;
//         n1=max(n1,x1);
//         m=max(m,y1);
//     }
//     n=n1;
    
//     Try(0,0,a[0][0]);
   
//     if(res>0){
//         cout<<res<<" "<<road;
//     }
//     else{
//         cout<<-1;
//     }
 
//     return 0;
// }
