#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

/*=================================================*/
/*
    # SEEING OTHERS CODE WON'T MAKE YOU SMARTER #
*/
/*=================================================*/
using namespace std;

int main()
{
    long long int len;
    long long int target;
    vector<long long int> coins;
    cin >> len >> target;
    for (long long int it = 0; it < len; it++)
    {
        long long int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    vector<long long int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for (int it = 0; it < len; it++)
    {
        for (int it2 = 0; it2 <= target; it2++)
        {
            if (it2 - coins[it] >= 0)
            {
                dp[it2] = min(dp[it2], dp[it2 - coins[it]] + 1);
            }
        }
    }

    cout << (dp[target] == INT_MAX ? -1 : dp[target]);
    return 0;
}