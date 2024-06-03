#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i].first >> times[i].second;
    }

    // Sort by ending time (ascending)
    sort(times.begin(), times.end(),
         [](const auto &a, const auto &b) { return a.second < b.second; });

    int count = 0;
    int currentEndTime = -1; // Initialize to before any movie starts

    for (const auto &movie : times) {
        if (movie.first >= currentEndTime) { // If movie doesn't overlap
            count++;
            currentEndTime = movie.second;
        }
    }

    cout << count << endl;
    return 0;
}
