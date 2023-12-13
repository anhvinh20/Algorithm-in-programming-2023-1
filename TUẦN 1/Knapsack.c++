/* A Naive recursive implementation of 
0-1 Knapsack problem */
#include <bits/stdc++.h> 
using namespace std;
int n;
int W;
int c[20];
int d[20];

int knapSack(int W, int wt[], int val[], int n) 
{ 
	if (n == 0 || W == 0) // so item=0, W=0 thì break
		return 0; 

	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1); 

	// Return the maximum of two cases: 
	// (1) nth item included 
	// (2) not included 
	else
		return max( 
			val[n - 1] 
				+ knapSack(W - wt[n - 1], wt, val, n - 1), 
			knapSack(W, wt, val, n - 1)); 
} 

// Driver code 
int main() 
{ 
	cin >> n ;
    cin >> W ;
    for( int i=0; i<n ;i++){
            cin >> c[i];
    }
    for( int i=0; i<n ;i++){
            cin >> d[i];
    }
    cout << knapSack(W, d, c, n); 

	return 0; 
} 

