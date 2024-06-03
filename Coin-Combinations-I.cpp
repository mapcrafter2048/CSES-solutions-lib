#include <iostream>
#include <vector>

using namespace std;

/*
Updated dp table in iteration 1, inner loop iteration 0:
1 0 0 0 0 0 0 0 0 0
Updated dp table in iteration 1, inner loop iteration 1:
1 0 0 0 0 0 0 0 0 0
Updated dp table in iteration 1, inner loop iteration 2:
1 0 0 0 0 0 0 0 0 0
Updated dp table after: 1 iteration
1 0 0 0 0 0 0 0 0 0
Updated dp table in iteration 2, inner loop iteration 0:
1 0 1 0 0 0 0 0 0 0
Updated dp table in iteration 2, inner loop iteration 1:
1 0 1 0 0 0 0 0 0 0
Updated dp table in iteration 2, inner loop iteration 2:
1 0 1 0 0 0 0 0 0 0
Updated dp table after: 2 iteration
1 0 1 0 0 0 0 0 0 0
Updated dp table in iteration 3, inner loop iteration 0:
1 0 1 0 0 0 0 0 0 0
Updated dp table in iteration 3, inner loop iteration 1:
1 0 1 1 0 0 0 0 0 0
Updated dp table in iteration 3, inner loop iteration 2:
1 0 1 1 0 0 0 0 0 0
Updated dp table after: 3 iteration
1 0 1 1 0 0 0 0 0 0
Updated dp table in iteration 4, inner loop iteration 0:
1 0 1 1 1 0 0 0 0 0
Updated dp table in iteration 4, inner loop iteration 1:
1 0 1 1 1 0 0 0 0 0
Updated dp table in iteration 4, inner loop iteration 2:
1 0 1 1 1 0 0 0 0 0
Updated dp table after: 4 iteration
1 0 1 1 1 0 0 0 0 0
Updated dp table in iteration 5, inner loop iteration 0:
1 0 1 1 1 1 0 0 0 0
Updated dp table in iteration 5, inner loop iteration 1:
1 0 1 1 1 2 0 0 0 0
Updated dp table in iteration 5, inner loop iteration 2:
1 0 1 1 1 3 0 0 0 0
Updated dp table after: 5 iteration
1 0 1 1 1 3 0 0 0 0
Updated dp table in iteration 6, inner loop iteration 0:
1 0 1 1 1 3 1 0 0 0
Updated dp table in iteration 6, inner loop iteration 1:
1 0 1 1 1 3 2 0 0 0
Updated dp table in iteration 6, inner loop iteration 2:
1 0 1 1 1 3 2 0 0 0
Updated dp table after: 6 iteration
1 0 1 1 1 3 2 0 0 0
Updated dp table in iteration 7, inner loop iteration 0:
1 0 1 1 1 3 2 3 0 0
Updated dp table in iteration 7, inner loop iteration 1:
1 0 1 1 1 3 2 4 0 0
Updated dp table in iteration 7, inner loop iteration 2:
1 0 1 1 1 3 2 5 0 0
Updated dp table after: 7 iteration
1 0 1 1 1 3 2 5 0 0
Updated dp table in iteration 8, inner loop iteration 0:
1 0 1 1 1 3 2 5 2 0
Updated dp table in iteration 8, inner loop iteration 1:
1 0 1 1 1 3 2 5 5 0
Updated dp table in iteration 8, inner loop iteration 2:
1 0 1 1 1 3 2 5 6 0
Updated dp table after: 8 iteration
1 0 1 1 1 3 2 5 6 0
Updated dp table in iteration 9, inner loop iteration 0:
1 0 1 1 1 3 2 5 6 5
Updated dp table in iteration 9, inner loop iteration 1:
1 0 1 1 1 3 2 5 6 7
Updated dp table in iteration 9, inner loop iteration 2:
1 0 1 1 1 3 2 5 6 8
Updated dp table after: 9 iteration
1 0 1 1 1 3 2 5 6 8
*/

int main() {
    long long int len;
    long long int target;
    cin >> len >> target;
    vector<long long int> coins(len);
    for (int i = 0; i < len; i++) {
        cin >> coins[i];
    }

    vector<long long int> dp(target + 1, 0);
    dp[0] = 1;
    for (int it = 1; it <= target; it++) {
        for (int it2 = 0; it2 < len; it2++) {
            if (coins[it2] <= it) {
                dp[it] = (dp[it] + dp[it - coins[it2]]) % 1000000007;
            }
        }
    }

    cout << dp[target] << endl;
    return 0;
}
