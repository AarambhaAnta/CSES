
#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define int long long
#define nl '\n'
#define sp ' '
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

// I/O Fast
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Debug Macro
#ifndef ONLINE_JUDGE
#define debug(x)                                                                                   \
    cerr << #x << " = ";                                                                           \
    _print(x);                                                                                     \
    cerr << nl;
#else
#define debug(x)
#endif

// Debug Utilities
void _print(int x) {
    cerr << x;
}
void _print(string x) {
    cerr << x;
}
void _print(char x) {
    cerr << x;
}
void _print(bool x) {
    cerr << (x ? "true" : "false");
}
void _print(double x) {
    cerr << x;
}
template <typename T, typename V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <typename T>
void _print(vector<T> v) {
    cerr << "[";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <typename T>
void _print(set<T> s) {
    cerr << "{";
    for (T i : s) {
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e18;
const double EPS = 1e-9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

// Aliases
using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;

// Input / Output helpers
template <typename T>
void vin(vector<T>& a) {
    for (auto& x : a)
        cin >> x;
}
template <typename T>
void vout(const vector<T>& a) {
    for (auto x : a)
        cout << x << sp;
    cout << nl;
}


//======================================== Solution Logic ========================================//

void test() {
    // your solution for each testcase
    int n, x;
    cin >> n >> x;
    vi wei(n);
    vin(wei);

    vii dp(1 << n, {n + 1, 0});  // dp->{rides, weight}

    dp[0] = {1, 0};
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                int prev = mask ^ (1 << i);
                auto [rides, lWeight] = dp[prev];

                if (wei[i] + lWeight <= x) {
                    dp[mask] = min(dp[mask], {rides, lWeight + wei[i]});
                } else {
                    dp[mask] = min(dp[mask], {rides + 1, wei[i]});
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first << nl;
}

// Driver Code
signed main() {
    fastIO();
    int tc = 1;
    // cin >> tc; // Uncomment for multiple test cases
    while (tc--)
        test();
    return 0;
}
