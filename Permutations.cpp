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
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    } else if (n == 2) {
        cout << "NO SOLUTION" << endl;
        return 0;
    } else if (n == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    } else {
        vector<long long int> even;
        vector<long long int> odd;
        for (long long int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                even.push_back(i);
            } else {
                odd.push_back(i);
            }
        }
        for (long long int i = 0; i < even.size(); i++) {
            cout << even[i] << " ";
        }
        for (long long int i = 0; i < odd.size(); i++) {
            cout << odd[i] << " ";
        }
    }
    return 0;
}