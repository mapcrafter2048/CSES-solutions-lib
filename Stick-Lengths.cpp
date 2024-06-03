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
    cin >> len;
    vector<long long int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long int median = arr[len / 2];

    long long int cost = 0;
    for (long long int i = 0; i < len; i++) {
        cost += abs(arr[i] - median);
    }

    cout << cost << endl;

    return 0;
}