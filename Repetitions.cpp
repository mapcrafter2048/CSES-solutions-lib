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
    string s;
    cin >> s;
    int max = 0;
    int count = 1;
    for (int it = 0; it < s.size(); it++)
    {
        if (s[it] == s[it + 1])
        {
            count++;
        }
        else
        {
            if (count > max)
            {
                max = count;
            }
            count = 1;
        }
    }
    cout << max << endl;
    return 0;
}
