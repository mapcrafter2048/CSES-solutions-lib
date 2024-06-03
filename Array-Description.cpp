#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    long long int len;
    long long int upperBound;
    cin >> len >> upperBound;

    vector<long long int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    vector<long long int> dp(len - 1);
    for (int i = 0; i < upperBound; i++) {
        for (int j = 0; j < len; j++) {
            if (i == 0) {
                if (j == 0) {
                    dp[j] = 1;
                } else {
                    dp[j] = 0;
                }
            } else {
                dp[j] = 0;
                if (j - 1 >= 0) {
                    dp[j] += dp[j - 1];
                }
                if (j + 1 < len) {
                    dp[j] += dp[j + 1];
                }
                dp[j] %= 1000000007;
            }
        }
    }

    long long int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += dp[i];
        ans %= 1000000007;
    }

    cout << ans << endl;
    return 0;
}