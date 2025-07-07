
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

// Size based implementation
struct UnionFind {
    int n;               // Number of elements
    int set_size;        // Number of disjoint sets
    vector<int> parent;  // Parent array
    vector<int> rank;    // Rank array (size of subtree)

    // Constructor
    UnionFind(int a) {
        n = set_size = a;
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
            make_set(i);
    }

    // Build the Initial parent[] and rank[]
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 1;
    }

    // Find with path compression
    int find_set(int x) {
        if (x != parent[x])
            return parent[x] = find_set(parent[x]);
        return x;
    }

    // Union with rank optimization
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] >= rank[b]) {
                parent[b] = a;
                rank[a] += rank[b];
            } else {
                parent[a] = b;
                rank[b] += rank[a];
            }
            set_size -= 1;
        }
    }

    // Reset to initial state
    void reset() {
        set_size = n;
        for (int i = 1; i <= n; ++i)
            make_set(i);
    }

    // Get number of disjoint sets
    int size() {
        return set_size;
    }

    // Print the parent array
    void print() {
        for (int i = 1; i <= n; ++i)
            cout << i << " -> " << parent[i] << '\n';
    }
};

//======================================== Solution Logic ========================================//

void test() {
    // your solution for each testcase
    int n, m;
    cin >> n >> m;
    UnionFind dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.union_set(u, v);
    }

    set<int> comp;
    for (int i = 1; i <= n; i++) {
        comp.insert(dsu.find_set(i));
    }

    cout << dsu.set_size - 1 << nl;
    vi res(all(comp));
    for (int i = 1; i < dsu.set_size; i++) {
        cout << res[i - 1] << sp << res[i] << nl;
    }
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
