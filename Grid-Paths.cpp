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

long long int solve(vector<vector<char>> &grid, long long int i,
                    long long int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == '*') {
        return 0;
    }
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
        return 1;
    }
    grid[i][j] = '*';
    long long int ans = 0;
    ans += solve(grid, i + 1, j);
    ans += solve(grid, i - 1, j);
    ans += solve(grid, i, j + 1);
    ans += solve(grid, i, j - 1);
    grid[i][j] = '.'; // Backtrack
    return ans;
}

int main() {
    long long int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (long long int i = 0; i < n; i++) {
        for (long long int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << solve(grid, (std::size_t)0, (std::size_t)0) << endl;

    return 0;
}