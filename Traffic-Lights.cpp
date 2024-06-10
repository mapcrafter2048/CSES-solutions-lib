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

/*
 * So in this question we have to find the maximum distance between two traffic
 * lights We can use a set to store the positions of the traffic lights We can
 * use a multiset to store the lengths between the traffic lights We can insert
 * 0 and street in the set and street - 0 in the multiset Then we can insert the
 * positions of the traffic lights in the set We can find the previous and next
 * positions of the traffic light We can erase the length between the previous
 * and next positions from the multiset We can insert the length between the
 * previous and the new traffic light and the new traffic light and the next
 * position in the multiset We can print the maximum length in the multiset Lets
 * do a dry run with an examples of street = 8 and traffic lights = 3 and
 * positions = 3 6 2 initally our position set will be {0, 8} and distances
 * multiset will be {8} now we enter the loop for i = 0, we insert 3 in the set
 * and find the previous and next positions of 3 which are 0 and 8 then we will
 * erase 8 - 0 from our multisets and insert 3 - 0 and 8 - 3 in the multiset now
 * our set will be {0, 3, 8} and distances multiset will be {3, 5} we will then
 * print the last element of the set lengths which is 5 for i = 1, we insert 6
 * in the set and find the previous and next positions of 6 which are 3 and 8
 * then we will erase 8 - 3 from our multisets and insert 6 - 3 and 8 - 6 in the
 * multiset now our set will be {0, 3, 6, 8} and distances multiset will be {2,
 * 3, 3} we will then print the last element of the set lengths which is 3 for i
 * = 2, we insert 2 in the set and find the previous and next positions of 2
 * which are 0 and 3 then we will erase 3 - 0 from our multisets and insert 2 -
 * 0 and 3 - 2 in the multiset now our set will be {0, 2, 3, 6, 8} and distances
 * multiset will be {2, 1, 2, 3} we will then print the last element of the set
 * lengths which is 2 so the answer will be 5 3 3
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int street;
    long long int len;
    cin >> street >> len;
    vector<long long int> lights(len);
    set<long long int> positions;
    multiset<long long int> lengths;
    positions.insert(0);
    positions.insert(street);
    lengths.insert(street - 0);

    for (long long int i = 0; i < len; i++) {
        long long int added;
        cin >> added;
        positions.insert(added);
        auto it = positions.find(added);
        long long int previousVal = *prev(it);
        long long int nextVal = *next(it);
        lengths.erase(lengths.find(nextVal - previousVal));
        lengths.insert(added - previousVal);
        lengths.insert(nextVal - added);
        cout << *lengths.rbegin() << " ";
    }

    return 0;
}