
// C(k,n) mod 1e9+7
#include<iostream>
#define MAX 1000
using namespace std;

const long long MOD=1e9+7;
int n,k;
long long lkup[MAX][MAX];

// C(n,k) = C(n-1,k) + C(n-1,k-1)

long long C(int n, int k) {
	if (lkup[n][k]>0) return lkup[n][k];
	
	if (k==0||k==n) {
		lkup[n][k]=1; return 1;
	}
	
	lkup[n][k]=(C(n-1,k)+C(n-1,k-1))%MOD;
	return lkup[n][k];
}

int main() {
	cin>>k>>n;
	cout<<C(n,k)%MOD;
	return 0;
}
