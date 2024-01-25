#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
    int x, y, gold;
    Treasure(int x, int y, int gold) : x(x), y(y), gold(gold) {}
};

bool compare(const Treasure& a, const Treasure& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int maxGold(vector<Treasure>& treasures) {
    sort(treasures.begin(), treasures.end(), compare);
    int n = treasures.size();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        dp[i] = treasures[i].gold; // Start with the gold at this treasure
        for (int j = 0; j < i; ++j) {
            // Check if we can move from treasure j to i
            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    vector<Treasure> treasures;

    for (int i = 0; i < n; ++i) {
        int x, y, gold;
        cin >> x >> y >> gold;
        treasures.emplace_back(x, y, gold);
    }

    cout << maxGold(treasures) << endl;
    return 0;
}
