
#include <bits/stdc++.h>
using namespace std;

// Type Aliases
// #define int long long
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
const int INF = 1e9;
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
int n, m;
int dp[505][505];
int rec(int l, int r) {
    if (l == r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int count = INF;
    for (int i = 1; i < l; i++) {
        count = min(count, 1 + rec(i, r) + rec(l - i, r));
    }

    for (int j = 1; j < r; j++) {
        count = min(count, 1 + rec(l, j) + rec(l, r - j));
    }
    return dp[l][r] = count;
}
void test() {
    // your solution for each testcase
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << rec(n, m) << nl;
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
