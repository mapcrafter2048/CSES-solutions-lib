#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int len;
    cin >> len;

    vector<long long int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long int reachableSum = 0; // Maximum sum we can reach so far

    for (int i = 0; i < len; i++) {
        // If the current coin value exceeds the reachable sum + 1,
        // we've found the smallest impossible sum.
        if (arr[i] > reachableSum + 1) {
            break;
        }

        // Otherwise, update the reachable sum
        reachableSum += arr[i];
    }

    // The smallest impossible sum is one more than the maximum reachable sum
    cout << reachableSum + 1 << endl;

    return 0;
}
