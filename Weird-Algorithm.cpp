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

/*===============================================*/
/*
     SEEING OTHERS CODE WON'T MAKE YOU SMARTER
*/
/*===============================================*/
using namespace std;

vector<long long int> solve(long long int n)
{
    vector<long long int> result;
    if (n == 1)
    {
        result.push_back(1);
        return result;
    }
    else if (n % 2 == 0)
    {
        result = solve(n / 2);
        result.push_back(n);
        return result;
    }
    else
    {
        result = solve(3 * n + 1);
        result.push_back(n);
        return result;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> result = solve(n);
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }

    return 0;
}