#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    // 2D grid to store the maze
    vector<vector<char>> grid(row, vector<char>(col));

    // 2D visited array to keep track of visited cells
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // 2D parent array to store the parent of each cell
    vector<vector<pair<int, int>>> parent(
        row, vector<pair<int, int>>(col, {-1, -1}));

    // Arrays to represent movements in four directions (up, right, down, left)
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    // Characters representing directions (up, right, down, left)
    char directions[4] = {'U', 'R', 'D', 'L'};

    // Variables to store the starting and ending positions
    pair<int, int> startIndex;
    pair<int, int> endIndex;

    // Input the maze
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') { // Mark the starting position 'A'
                startIndex = {i, j};
            } else if (grid[i][j] == 'B') { // Mark the ending position 'B'
                endIndex = {i, j};
            }
        }
    }

    // Queue for BFS traversal
    queue<pair<int, int>> q;
    q.push(startIndex);                                  // Start BFS from 'A'
    visited[startIndex.first][startIndex.second] = true; // Mark 'A' as visited

    // BFS traversal
    while (!q.empty()) {
        int currRow = q.front().first;  // Get current row
        int currCol = q.front().second; // Get current column
        q.pop();

        // Explore neighbors in all four directions
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + delRow[i]; // Calculate new row
            int newCol = currCol + delCol[i]; // Calculate new column

            // Check if the new position is valid, not visited, and not a wall
            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col &&
                !visited[newRow][newCol] && grid[newRow][newCol] != '#') {
                visited[newRow][newCol] = true;              // Mark as visited
                parent[newRow][newCol] = {currRow, currCol}; // Store the parent
                q.push(
                    {newRow, newCol}); // Add to queue for further exploration
            }
        }
    }

    // Check if the destination 'B' is reachable
    if (visited[endIndex.first][endIndex.second]) {
        cout << "YES" << endl;

        // Reconstruct the path
        vector<char> path;
        pair<int, int> current = endIndex; // Start at 'B'

        while (current != startIndex) { // Backtrack until 'A'
            pair<int, int> prev =
                parent[current.first][current.second]; // Get parent

            // Determine the direction taken to reach the current cell from its
            // parent
            for (int i = 0; i < 4; i++) {
                if (current.first == prev.first + delRow[i] &&
                    current.second == prev.second + delCol[i]) {
                    path.push_back(
                        directions[i]); // Add the direction to the path
                    break;
                }
            }
            current = prev; // Move to the parent cell
        }

        reverse(path.begin(),
                path.end()); // Reverse the path (as it was built backward)

        cout << path.size() << endl; // Output path length
        for (char c : path) {
            cout << c; // Output each direction
        }
        cout << endl;
    } else {
        cout << "NO" << endl; // No path exists
    }

    return 0;
}
