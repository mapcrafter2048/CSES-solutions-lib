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
    long long int max_weight;
    cin >> len >> max_weight;
    vector<long long int> weights(len);
    for (long long int i = 0; i < len; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int begin = 0;
    int end = len - 1;
    int answer = 0;
    while (begin < end) {
        if (weights[begin] + weights[end] <= max_weight) {
            begin++;
            end--;
            answer++;
        } else {
            end--;
        }
    }
    cout << len - answer << endl;
    return 0;
}