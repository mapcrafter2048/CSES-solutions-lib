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

    map<int, int> freq;
    int i = 0;
    int j = 0;
    int maxLen = 0;
    int currLen = 0;

    while (j < len) {
        if (freq.find(arr[j]) == freq.end() || freq[arr[j]] == 0) {
            freq[arr[j]]++;
            currLen++;
            maxLen = max(maxLen, currLen);
            j++;
        } else {
            currLen--;
            freq[arr[i]]--;
            i++;
        }
    }

    cout << maxLen << endl;

    return 0;
}

/*
    * lets us dry run this approach on an example of [2, 3, 4 ,5, 3, 10, 9, 8
   ,7]
    * so on the first iteration our map will be [2 : 1 , 3 : 0, 4 : 0, 5 : 0, 6
   : 0, 7 : 0, 8 : 0, 9 : 0, 10 : 0] and j = 1 max_len = 1, currLne = 1
    * on the second iteration our map will be [2 : 1 , 3 : 1, 4 : 0, 5 : 0, 6 :
   0, 7 : 0, 8 : 0, 9 : 0, 10 : 0] and j = 2, max_len = 2, currLne = 2
    * on the third iteration our map will be [2 : 1 , 3 : 1, 4 : 1, 5 : 0, 6 :
   0, 7 : 0, 8 : 0, 9 : 0, 10 : 0] and j = 3, max_len = 3, currLne = 3
    * on the fourth iteration our map will be [2 : 1 , 3 : 1, 4 : 1, 5 : 1, 6 :
   0, 7 : 0, 8 : 0, 9 : 0, 10 : 0] and j = 4, max_len = 4, currLne = 4
    * on on the fifth iteration we will not go into the first else block as we
   are able to find 3 again in our map so this => that 3 is duplicate hence we
   are doing to go in the else condition
    * in the else condition we are going to decrement the value of frequency of
   2 to be 0 hence our map will look like [2 : 0 , 3 : 1, 4 : 1, 5 : 1, 6 : 0, 7
   : 0, 8 : 0, 9 : 0, 10 : 0] and j is still 4 but now currLen is 3 and i = 1
    * again in the next iteration we are still able to find 3 hence we will go
   in to the else block and then we are going to decrement the value of
   frequency of 3 to be 0 hence our map will look like [2 : 0 , 3 : 0, 4 : 1, 5
   : 1, 6 : 0, 7 : 0, 8 : 0, 9 : 0, 10 : 0]
    * now when we move to the next itartion we cannot find 3 hence we will go
   into the if block and then continue

*/