#include<bits/stdc++.h>
using namespace std;

int a[1000000];
long long f[1000000][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	long long maxval=LLONG_MIN;
	
	for (int i=0;i<n;i++) {
		cin>>a[i];
		if (a[i]%2==0) {
			if (i==0) {
				f[i][0]=a[i];
				f[i][1]=LLONG_MIN;	
			} else {
				f[i][0]=max(f[i-1][0]+a[i],(long long)a[i]);
				f[i][1]= f[i-1][1]==LLONG_MIN ? LLONG_MIN : f[i-1][1]+a[i];
			}
		} else {
			if (i==0) {
				f[i][0]=LLONG_MIN;
				f[i][1]=a[i];
			} else {
				f[i][0]=f[i-1][1]+a[i];
				f[i][1]= f[i-1][0]==LLONG_MIN ? a[i] : max(f[i-1][0]+a[i],(long long)a[i]);
			}
		}
		maxval=max(maxval,f[i][0]);
	}
	cout << maxval;
}
