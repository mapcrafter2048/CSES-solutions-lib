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
    * so in this examples we are taking the help of a data structure called
   multiset due to performance and also it allows dulpicated values and is
   sorted
    * so what we are essentailly doing is that when when our mutliset is empty
   we just insert the value in the set
    * if the set is not empty we find the upper bound of the value in the set
   and if it is not the end of the set we erase the value and insert the new
   value
    * lets do a dry run of it
    * [3, 4, 2, 1, 5, 3, 4, 3, 2]
    * so lets us walk throught how this thing will works
    * on i = 0 since multiset is empty we will insert 3
    * on i = 1 our arr[i] = 4 and the upperbound is not present so we insert 4
   (it = tower.end())
    * on i = 2 our arr[i] = 2 and the upperbound is present so we erase the
   upperbound and essentailly replace it with arr[i]
    * on i = 3 our arr[i] = 1 and the upperbound is present so we erase the
   upperbound and essentailly replace it with arr[i]
    * on i = 4 our arr[i] = 5 and the upperbound is not present so we insert 5
   (it = tower.end())
    * on i = 5 our arr[i] = 3 and the upperbound is present so we erase the
   upperbound and essentailly replace it with arr[i]
    * on i = 6 our arr[i] = 4 and the upperbound is present so we erase the
   upperbound and essentailly replace it with arr[i]
    * on i = 7 our arr[i] = 3 and the upperbound is present so we erase the
   upperbound and essentailly replace it with arr[i]
    * on i = 8 our arr[i] = 2 and the upperbound is present so we erase the
   upperbound and essentailly replace it with arr[i]
    * so the answer is 3
    * The curx of the problem is that we are essentailly replacing the value in
   the set with the new value if the upperbound is present
    * and if the upperbound is not present we insert the value in the set
    * and the answer is the size of the set
    * the time complexity of the solution is O(nlogn) and the space complexity
   is O(n)

*/

int main() {
    long long int len;
    cin >> len;
    vector<long long int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    multiset<long long int> towers;
    for (int i = 0; i < len; i++) {
        if (towers.size() == 0) {
            towers.insert(arr[i]);
        } else {
            auto it = towers.upper_bound(arr[i]);
            if (it == towers.end()) {
                towers.insert(arr[i]);
            } else {
                towers.erase(it);
                towers.insert(arr[i]);
            }
        }
    }

    cout << towers.size() << endl;

    return 0;
}