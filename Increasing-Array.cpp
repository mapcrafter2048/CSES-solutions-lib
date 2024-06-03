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

/*=================================================*/
/*
    # SEEING OTHERS CODE WON'T MAKE YOU SMARTER #
*/
/*=================================================*/
using namespace std;

int main() {
    long long int len;
    cin >> len;
    vector<long long int> arr(len);
    for (long long int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    long long int counts = 0;
    for (long long int i = 1; i < len; i++) {
        if (arr[i] > arr[i - 1]) {
            continue;
        } else {
            counts += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << counts << endl;
    return 0;
}