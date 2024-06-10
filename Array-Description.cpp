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

int main() {
    long long int len;
    long long int upperBound;
    cin >> len >> upperBound;
    vector<long long int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    vector<vector<long long int>> dp(len + 1,
                                     vector<long long int>(upperBound + 1, 0));

    if (arr[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < len; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= upperBound; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j - 1 > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j + 1 <= upperBound) {
                    dp[i][j] += dp[i - 1][j + 1];
                }

                dp[i][j] %= 1000000007;
            }
        } else {
            dp[i][arr[i]] += dp[i - 1][arr[i]];
            if (arr[i] - 1 > 0) {
                dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
            }
            if (arr[i] + 1 <= upperBound) {
                dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
            }
            dp[i][arr[i]] %= 1000000007;
        }
    }

    long long int ans = 0;
    for (int i = 1; i <= upperBound; i++) {
        ans += dp[len - 1][i];
        ans %= 1000000007;
    }

    cout << ans << endl;

    return 0;
}