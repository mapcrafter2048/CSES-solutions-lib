#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

/*=================================================*/
/*
    # SEEING OTHERS CODE WON'T MAKE YOU SMARTER #
*/
/*=================================================*/
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}