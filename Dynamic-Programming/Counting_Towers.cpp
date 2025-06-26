
#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define int         long long
#define nl          '\n'
#define sp          ' '
#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define all(x)      (x).begin(), (x).end()

// I/O Fast
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Debug Macro
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = "; _print(x); cerr << nl;
#else
    #define debug(x)
#endif

// Debug Utilities
void _print(int x)       { cerr << x; }
void _print(string x)    { cerr << x; }
void _print(char x)      { cerr << x; }
void _print(bool x)      { cerr << (x ? "true" : "false"); }
void _print(double x)    { cerr << x; }
template <typename T, typename V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <typename T> void _print(vector<T> v) { cerr << "["; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <typename T> void _print(set<T> s) { cerr << "{"; for (T i : s) {_print(i); cerr << " ";} cerr << "}"; }

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e18;
const double EPS = 1e-9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

// Aliases
using vi  = vector<int>;
using vb  = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;

// Input / Output helpers
template<typename T> void vin(vector<T>& a) { for (auto &x : a) cin >> x; }
template<typename T> void vout(const vector<T>& a) { for (auto x : a) cout << x << sp; cout << nl; }


//======================================== Solution Logic ========================================//
const int maxn = 1e6 + 10;
vector<vi> dp(1e6 + 10, vi(8, 0));

void rec(){
    for (int i = 0; i < 8; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5) {
                dp[i][j] =
                    (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) %
                    MOD;
            } else {
                dp[i][j] = (dp[i - 1][2] + dp[i - 1][6] + dp[i - 1][7]) % MOD;
            }
        }
    }
}
void test() {
    // your solution for each testcase
    int n;
    cin >> n;
    cout << (dp[n - 1][2] + dp[n - 1][6]) % MOD << nl;
}

// Driver Code
signed main() {
    fastIO();
    rec();
    int tc = 1;
    cin >> tc; // Uncomment for multiple test cases
    while (tc--) test();
    return 0;
}
