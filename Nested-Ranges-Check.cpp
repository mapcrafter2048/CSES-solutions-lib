#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define debarr(a, n)                                                           \
    std::cout << #a << " : ";                                                  \
    for (int i = 0; i < n; i++)                                                \
        std::cerr << a[i] << " ";                                              \
    std::cerr << std::endl;
#define debmat(mat, row, col)                                                  \
    std::cout << #mat << " :\n";                                               \
    for (int i = 0; i < row; i++) {                                            \
        for (int j = 0; j < col; j++)                                          \
            std::cerr << mat[i][j] << " ";                                     \
        std::cerr << std::endl;                                                \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::pair<S, T> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<S, T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::multiset<T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
std::ostream &operator<<(std::ostream &os, const std::map<S, T> &p) {
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T> void dbs(std::string str, T t) {
    std::cerr << str << " : " << t << "\n";
}
template <class T, class... S> void dbs(std::string str, T t, S... s) {
    int idx = str.find(',');
    std::cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T> void prc(T a, T b) {
    std::cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a)
            std::cerr << ", ";
        std::cerr << *i;
    }
    std::cerr << "]\n";
}
long long int binpow(long long int b, long long int p, long long int mod) {
    long long int ans = 1;
    b %= mod;
    for (; p; p >>= 1) {
        if (p & 1)
            ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}

using namespace std;

struct ranges {
    // The left and right ends of the range and its index in
    // the input order
    int l, r, in;

    // Overloads the < operator for sorting
    bool operator<(const ranges &other) const {
        // If left ends are equal, the range with larger
        // right end comes first
        if (l == other.l)
            return r > other.r;
        // Otherwise, the range with smaller left end comes
        // first
        return l < other.l;
    }
};

// Function to determine for each range if it contains some
// other range and if some other range contains it.
vector<vector<int>> checkrange(vector<vector<int>> &r, int n) {
    vector<ranges> range(n);
    vector<int> contains(n), contained(n);

    for (int i = 0; i < n; i++) {
        range[i].l = r[i][0];
        range[i].r = r[i][1];
        range[i].in = i;
    }

    // Sorts the ranges
    sort(range.begin(), range.end());

    // Checks if a range contains another
    int minEnd = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        // If the right end of the current range is greater
        // than minEnd, it contains another
        if (range[i].r >= minEnd)
            contains[range[i].in] = 1;

        // Update minEnd
        minEnd = min(minEnd, range[i].r);
    }

    // Checks if a range is contained by another
    int maxEnd = 0;
    for (int i = 0; i < n; i++) {
        // If the right end of the current range is less
        // than maxEnd, it is contained by another
        if (range[i].r <= maxEnd)
            contained[range[i].in] = 1;

        // Update maxEnd
        maxEnd = max(maxEnd, range[i].r);
    }

    // Returns the contains and contained vector
    return {contains, contained};
}

// Driver code
int main() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> r[i][0] >> r[i][1];

    vector<vector<int>> ans = checkrange(r, n);
    for (int i = 0; i < n; i++)
        cout << ans[0][i] << " ";

    cout << endl;

    for (int i = 0; i < n; i++)
        cout << ans[1][i] << " ";

    cout << endl;
    return 0;
}