
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
#define rall(x) (x).rbegin(), (x).rend()

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
const array<int, 4> dx = {0, 1, 0, -1};
const array<int, 4> dy = {1, 0, -1, 0};
const array<char, 4> dir = {'R', 'D', 'L', 'U'};

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
vector<string> grid;
vector<vi> dis;
vector<vii> par;

void bfs(pii src) {
    dis[src.ff][src.ss] = 0;
    par[src.ff][src.ss] = mp(-1, -1);

    queue<pii> q;
    q.push(src);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ni = x + dx[i], nj = y + dy[i];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] != '#' &&
                dis[ni][nj] > dis[x][y] + 1) {
                dis[ni][nj] = dis[x][y] + 1;
                par[ni][nj] = mp(x, y);
                q.push(mp(ni, nj));
            }
        }
    }
}
void test() {
    // your solution for each testcase
    cin >> n >> m;
    grid.assign(n, "");
    pii src = {-1, -1}, des = {-1, -1};
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        if (src.ss == -1 && grid[i].find('A') != string::npos) {
            src = mp(i, grid[i].find('A'));
        }
        if (des.ss == -1 && grid[i].find('B') != string::npos) {
            des = mp(i, grid[i].find('B'));
        }
    }

    dis.assign(n, vi(m, INF));
    par.assign(n, vii(m, {-1, -1}));

    bfs(src);

    if (dis[des.ff][des.ss] == INF) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
    cout << dis[des.ff][des.ss] << nl;

    string res;
    pii cur = des;
    while (cur != src) {
        pii p = par[cur.ff][cur.ss];
        for (int i = 0; i < 4; i++) {
            if (p.ff + dx[i] == cur.ff && p.ss + dy[i] == cur.ss) {
                res.pb(dir[i]);
                break;
            }
        }
        cur = p;
    }
    reverse(all(res));
    cout << res << nl;
}

//======================================== Driver Code ========================================//
signed main() {
    fastIO();
    int tc = 1;
    // cin >> tc; // Uncomment for multiple test cases
    while (tc--)
        test();
    return 0;
}
