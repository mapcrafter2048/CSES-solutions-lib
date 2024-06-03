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

void bfs(int row, int col, vector<vector<char>> &grid,
         vector<vector<bool>> &visited) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> delRow = {1, 0, -1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    visited[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
}

int numberOfRooms(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int count = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (grid[row][col] == '.' && !visited[row][col]) {
                bfs(row, col, grid, visited);
                count++;
            }
        }
    }
    return count;
}

int main() {
    long long int row;
    long long int col;
    cin >> row >> col;
    vector<vector<char>> grid(row, vector<char>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }

    cout << numberOfRooms(grid) << endl;
    return 0;
}