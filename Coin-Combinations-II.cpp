#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long int dp[1000001];

int main() {

    long long int len;
    long long int target;

    cin >> len >> target;

    vector<long long int> coins(len);

    for (int i = 0; i < len; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for (int i = 0; i < len; i++) {
        for (int weights = 0; weights <= target; weights++) {
            if (weights - coins[i] >= 0) {
                dp[weights] =
                    (dp[weights] + dp[weights - coins[i]]) % 1000000007;
            }
        }
    }

    cout << dp[target] << endl;

    return 0;
}