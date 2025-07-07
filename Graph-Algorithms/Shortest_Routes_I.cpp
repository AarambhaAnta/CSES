
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

struct Node {
    int u, w;
    bool operator>(const Node& other) const {
        return w > other.w;
    }
};

const int maxn = 1e5 + 5;
int n, m;
vector<pii> g[maxn];
int dis[maxn];

void dijkstra(Node start) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dis[start.u] = 0;
    pq.push({start.u, 0});
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.u;
        int w = node.w;
        if (w > dis[u])
            continue;

        for (auto [v, weight] : g[u]) {
            if (dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push({v, dis[v]});
            }
        }
    }
}
void test() {
    // your solution for each testcase
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(mp(v, w));
    }
    fill(dis, dis + n + 1, INF);
    dijkstra({1, 0});

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << sp;
    }
    cout << nl;
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
