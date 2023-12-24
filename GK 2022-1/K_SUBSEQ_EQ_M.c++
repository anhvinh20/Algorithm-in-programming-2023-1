// Nhập n,k,m , dãy có n số nguyên
// Tính Q là số dãy con có k phần tử và có tổng bằng m
// Output : Q

#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n,k,m;
	cin>>n>>k>>m;
	int a[n];
	int cnt=0;
	int sum=0;
	
	queue<int> q;
	for (int i=0;i<k;i++) {
		int x;cin>>x;
		sum+=x;
		q.push(x);
	}
	if (sum==m) cnt++;
	
	for (int i=0;i<n-k;i++) {
		int x;cin>>x;
		sum-=q.front(); q.pop();
		q.push(x);
		sum+=x;
		if (sum==m) cnt++;
	}
	
	cout<<cnt;
	return 0;
}
