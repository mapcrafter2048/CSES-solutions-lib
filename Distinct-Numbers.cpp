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
    long long int n;
    cin >> n;
    vector<long long int> values(n);
    for (long long int i = 0; i < n; i++) {
        cin >> values[i];
    }
    sort(values.begin(), values.end());
    long long int count = 1;
    for (long long int i = 1; i < n; i++) {
        if (values[i] != values[i - 1]) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}