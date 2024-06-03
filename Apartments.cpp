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
    long long int n, m, k;
    cin >> n >> m >> k;
    vector<long long int> applicants(n);
    vector<long long int> apartments(m);
    for (long long int i = 0; i < n; i++) {
        cin >> applicants[i];
    }
    for (long long int i = 0; i < m; i++) {
        cin >> apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int index1 = 0;
    int index2 = 0;
    int count = 0;
    while (index1 < n && index2 < m) {
        if (abs(applicants[index1] - apartments[index2]) <= k) {
            index1++;
            index2++;
            count++;
        } else if (applicants[index1] < apartments[index2]) {
            index1++;
        } else {
            index2++;
        }
    }
    cout << count << endl;

    return 0;
}