#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

void findMinDifferenceUtil(int index, int total, int sum, const vector<int>& bags, int& minDiff) {
    if (index == bags.size()) {
        int diff = abs((total - sum) - sum);
        if (diff < minDiff) {
            minDiff = diff;
        }
        return;
    }

    // Include current bag in first vehicle
    findMinDifferenceUtil(index + 1, total, sum + bags[index], bags, minDiff);

    // Exclude current bag from first vehicle
    findMinDifferenceUtil(index + 1, total, sum, bags, minDiff);
}

int findMinDifference(const vector<int>& bags) {
    int totalSum = 0;
    for (int value : bags) {
        totalSum += value;
    }

    int minDiff = INT_MAX;
    findMinDifferenceUtil(0, totalSum, 0, bags, minDiff);
    return minDiff;
}

int main() {
    int n;
    cin >> n;

    vector<int> bags(n);
    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    cout << findMinDifference(bags) << endl;

    return 0;
}
