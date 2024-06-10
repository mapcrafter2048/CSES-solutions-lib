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

    map<int, int> indices;
    for (int i = 0; i < len; i++) {
        indices[arr[i]] = i;
    }

    int count = 1;

    for (int i = 1; i < len; i++) {
        if (indices[i] > indices[i + 1]) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}