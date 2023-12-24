// Cho một dãy gồm các số nguyên đôi một khác nhau
// Nhập n,A,B
// Sao cho Q là số tập con của dãy n sao cho A<= tổng dãy <= B
// Output : Q

#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int n,A,B;
int a[MAX];
int sum=0;
int q=0; // đếm số lượng tập con thỏa mãn

void TRY(int i) {
	for (int k=0;k<=1;k++) {
		if (k) {
			sum += a[i];
			if (sum>=A && sum<=B) q++;
			if (i<n-1 && sum<=B) TRY(i+1);
			sum -= a[i];
		}
		else {
			if (i<n-1) TRY(i+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin>>n>>A>>B;
	
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	
	TRY(0);
	
	cout<<q;
	
	return 0;
}
