// // // a[i] + a[j] >= a[k]
// // #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // using namespace std;

// // const int MOD = 1000000007;

// // int countTriplets(vector<int>& a) {
// //     sort(a.begin(), a.end());
// //     long long count = 0;
// //     int n = a.size();

// //     for (int k = n - 1; k >= 2; k--) {
// //         int i = 0;
// //         int j = k - 1;
// //         while (i < j) {
// //             if (a[i] + a[j] >= a[k]) {
// //                 count += (j - i);
// //                 count %= MOD;
// //                 j--;
// //             } else {
// //                 i++;
// //             }
// //         }
// //     }
// //     return count;
// // }

// // int main() {
// //     int n;
// //     cin >> n;
// //     vector<int> a(n);
// //     for (int i = 0; i < n; i++) {
// //         cin >> a[i];
// //     }

// //     cout << countTriplets(a) << endl;
// //     return 0;
// // }


// a[i] + a[j] = a[k]
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countTriplets(vector<int>& a, int n) {
    unordered_map<int, int> sumCount;
    long long count = 0;

    // Count all possible sums for i < j
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sumCount[a[i] + a[j]]++;
        }
    }

    // Check if a[k] is a sum of any pair (i, j)
    for (int k = 0; k < n; k++) {
        if (sumCount.find(a[k]) != sumCount.end()) {
            count += sumCount[a[k]];
            count %= MOD;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << countTriplets(a, n) << endl;
    return 0;
}



