
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

//======================================== Fenwick Tree ========================================//
template <typename T>
class FenwickTree {
    vector<T> bit;
    int size;
    T MOD;

public:
    FenwickTree(int n, T mod = 1e9 + 7) : bit(n + 2, T()), size(n + 2), MOD(mod) {}
    void update(int i, T val) {
        for (; i < size; i += i & -i)
            bit[i] = (bit[i] + val) % MOD;
    }
    T query(int i) const {
        T res = T();
        for (; i > 0; i -= i & -i)
            res = (res + bit[i]) % MOD;
        return res;
    }
    T range(int l, int r) const {
        return (query(r) - query(l - 1) + MOD) % MOD;
    }
    void reset() {
        fill(bit.begin(), bit.end(), T());
    }
};

template <typename T>
vector<int> compress(const vector<T>& a, unordered_map<T, int>& compressed) {
    vector<T> sorted = a;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (int i = 0; i < (int)sorted.size(); ++i)
        compressed[sorted[i]] = i + 1;
    vector<int> result;
    for (auto x : a)
        result.push_back(compressed[x]);
    return result;
}

//======================================== Modulo ========================================//
template <typename T>
T modAdd(T a, T b, T m = MOD) {
    a %= m;
    b %= m;
    T res = a + b;
    return (res >= m ? res - m : res);
}
template <typename T>
T modSub(T a, T b, T m = MOD) {
    a %= m;
    b %= m;
    T res = a - b;
    return (res < 0 ? res + m : res);
}
template <typename T>
T modMul(T a, T b, T m = MOD) {
    a %= m;
    b %= m;
    return (a * b) % m;
}
template <typename T>
T modExp(T a, T b, T m = MOD) {
    a %= m;
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = modMul(res, a, m);
        a = modMul(a, a, m);
        b >>= 1;
    }
    return res;
}
template <typename T>
T modInv(T a, T m = MOD) {
    return modExp(a, m - 2, m);  // Requires m to be prime
}
template <typename T>
T modDiv(T a, T b, T m = MOD) {
    return modMul(a, modInv(b, m), m);
}

//======================================== Solution Logic ========================================//

void test() {
    // your solution for each testcase
    int n;
    cin >> n;
    vi arr(n);
    vin(arr);

    unordered_map<int, int> compressed;
    vi compA = compress(arr, compressed);

    FenwickTree<int> bit(n + 2);
    vi dp(n, 0);

    for (int i = 0; i < n; i++) {
        int comI = compA[i];
        int count = bit.query(comI - 1);
        dp[i] = modAdd(count, 1ll);
        bit.update(comI, dp[i]);
    }

    int result = accumulate(all(dp), 0ll) % MOD;
    cout << result << nl;
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
