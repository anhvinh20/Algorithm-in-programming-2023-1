// Cho dãy số nguyên n , thực hiện thao tác
// Insert x : thêm một phần tử x vào tập 
// Delete-max : xóa khỏi tập và trả về phần tử max trong tập
// Output : đưa ra các giá trị trả về của mỗi thao tác delete-max

#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	priority_queue<int> pq; // hàng đợi ưu tiên
	// lấy phần tử có độ ưu tiên cao nhất
	int n;
	cin >> n;
	
	while (n--) {
		int x;
		cin>>x;
		pq.push(x);
	}
	
	string cmd;
	cin >> cmd;
	while (cmd!="*") {
		if (cmd=="insert")  {
			int x;
			cin>>x;
			pq.push(x);
		} else {
			cout << pq.top() << endl;
			pq.pop();
		}
		cin >> cmd;
	}
	
	return 0;
}
