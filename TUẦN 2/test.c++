// // Cho một dãy gồm các số nguyên đôi một khác nhau
// // Nhập n,A,B
// // Sao cho Q là số tập con của dãy n sao cho A<= tổng dãy <= B
// // Output : Q

// #include<bits/stdc++.h>
// #define MAX 20
// using namespace std;

// int n,k;
// int a[MAX];
// int sum=0;
// int q=0; // đếm số lượng tập con thỏa mãn

// void TRY(int i) {
// 	for (int j=0;j<=1;j++) {
// 		if (j) {
// 			sum += a[i];
// 			if (sum>=k) q++;
// 			if (i<n-1 && sum>=k) TRY(i+1);
// 			sum -= a[i];
// 		}
// 		else {
// 			if (i<n-1) TRY(i+1);
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
// 	cin>>n>>k;
	
// 	for (int i=0;i<n;i++) {
// 		cin >> a[i];
// 	}
	
// 	TRY(0);
	
// 	cout<<q;
	
// 	return 0;
// }



#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<int> filterInRange(const int arr[], int size, int min, int max)
{
    vector<int> result;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= min && arr[i] <= max)
        {

            result.push_back(arr[i]); // Thêm vào vector nếu phần tử nằm trong khoảng
        }
    }
    return result;
}
int sumOfVector(const vector<int> &vec)
{
    int sum = 0;
    for (int element : vec)
    {
        sum += element; // Cộng dồn từng phần tử vào tổng
    }
    return sum;
}
int main()
{
    int n;
    int maxx;
    int count = 0;
    int minn;
    cin >> n >> minn >> maxx;
    int a[n + 10000];
    int a1, a2;
    int sum[n + 10000] = {0};
    bool check = true;
    vector<int> arr;
    for (int i = 10000; i < 10000 + n; i++)
    {
        cin >> a[i];
    }
    for (int i = 10000; i < 10000 + n; i++)
    {
        sum[i] = a[i];
        for (int j = i - maxx; j <= i - minn; j++)
        {
            if (sum[j] > count)
                count = sum[j];
        }
        sum[i] += count;
        count = 0;
    }
    for (int i = 10000; i < 10000 + n; i++)
    {
        if (sum[i] > count)
            count = sum[i];
    }
    cout << count;
}