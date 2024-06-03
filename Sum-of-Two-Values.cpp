#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long int len, target;
    cin >> len >> target;

    vector<long long int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    // Store the original indices of the elements
    vector<pair<long long int, long long int>> arrWithIndices(len);
    for (int i = 0; i < len; i++) {
        arrWithIndices[i] = {arr[i], i};
    }

    // Sort the array
    sort(arrWithIndices.begin(), arrWithIndices.end());

    long long int left = 0;
    long long int right = len - 1;

    while (left < right) {
        if (arrWithIndices[left].first + arrWithIndices[right].first ==
            target) {
            cout << arrWithIndices[left].second + 1 << " "
                 << arrWithIndices[right].second + 1 << endl;
            /*
            cout << arr[left] + arr[right] << endl;
            cout << left << " " << arr[left] << " " << right << " "
                 << arr[right] << " " << endl;
            */
            return 0; // Exit early since we found a pair
        } else if (arrWithIndices[left].first + arrWithIndices[right].first <
                   target) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
