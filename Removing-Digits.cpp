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

vector<int> getDigits(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

int solve(int n, vector<int> &dp) {
    if (n == 0) {
        return 0;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    vector<int> digits = getDigits(n);
    int ans = INT_MAX;
    for (int digit : digits) {
        if (digit == 0) {
            continue;
        }
        ans = min(ans, 1 + solve(n - digit, dp));
    }

    return dp[n] = ans;
}

int main() {
    long long int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp) << endl;
    return 0;
}