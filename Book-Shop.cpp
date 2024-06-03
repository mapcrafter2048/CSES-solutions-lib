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
    long long int totalPrice;
    cin >> len >> totalPrice;
    vector<long long int> bookPrices(len);
    vector<long long int> pages(len);

    for (int i = 0; i < len; i++) {
        cin >> bookPrices[i];
    }

    for (int i = 0; i < len; i++) {
        cin >> pages[i];
    }

    vector<vector<long long int>> dp(len + 1,
                                     vector<long long int>(totalPrice + 1));

    /*
     * dp[i][j] is the most number of pages that can be bought from
     * the first i books and by spending at most j amount of money.
     */

    for (int i = 1; i <= len; i++) {
        int currentCost = bookPrices[i - 1];
        int currentPages = pages[i - 1];

        for (int j = 1; j <= totalPrice; j++) {
            /*
             * if the current book is not bought, the the number of pages is
             * the same as number of pages bought for first i-1 books using
             * j amount of money
             */
            dp[i][j] = dp[i - 1][j];
            if (currentCost <= j) {
                /*
                 * if the current book can be bought, then store the most
                 * number of pages using the remaining money after buying
                 * the current book plus the pages for the current book.
                 * either the current book is bought or not bought.
                 * hence we take the maximum of the two.
                 */
                dp[i][j] =
                    max(dp[i][j], dp[i - 1][j - currentCost] + currentPages);
            }
        }
    }
    cout << dp[len][totalPrice] << endl;

    return 0;
}
