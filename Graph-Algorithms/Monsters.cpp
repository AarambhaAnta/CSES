
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

const int N = 1e5 + 5;
int n, m;
vector<string> grid;
vector<vi> personDis, monsterDis;
vector<vii> parent;
queue<pii> monster, person;

void mssp(queue<pii>& q, vector<vi>& dis, bool isPerson = false) {
    while (!q.empty()) {
        pii node = q.front();
        int x = node.ff;
        int y = node.ss;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ni = x + dx[i], nj = y + dy[i];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] != '#' &&
                dis[ni][nj] > dis[x][y] + 1) {
                dis[ni][nj] = dis[x][y] + 1;
                q.push({ni, nj});
                if (isPerson) {
                    parent[ni][nj] = {x, y};
                }
            }
        }
    }
}
void test() {
    // your solution for each testcase
    cin >> n >> m;
    personDis.assign(n, vi(m, INF));
    monsterDis.assign(n, vi(m, INF));
    parent.assign(n, vii(m, {-1, -1}));
    pii start;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.pb(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'M') {
                monsterDis[i][j] = 0;
                monster.push({i, j});
            } else if (s[j] == 'A') {
                start = {i, j};
                personDis[i][j] = 0;
                person.push({i, j});
            }
        }
    }

    mssp(monster, monsterDis);
    mssp(person, personDis, true);

    pii exit = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j : {0ll, m - 1}) {
            if (grid[i][j] != '#' && personDis[i][j] < monsterDis[i][j]) {
                exit = {i, j};
                break;
            }
        }
        if (exit.ff != -1)
            break;
    }
    if (exit.ff == -1) {
        for (int j = 0; j < m; j++) {
            for (int i : {0ll, n - 1}) {
                if (grid[i][j] != '#' && personDis[i][j] < monsterDis[i][j]) {
                    exit = {i, j};
                    break;
                }
            }
            if (exit.ff != -1)
                break;
        }
    }

    if (exit.ff == -1) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;

    pii cur = exit;
    string path;
    while (cur != start) {
        pii par = parent[cur.ff][cur.ss];
        for (int i = 0; i < 4; i++) {
            if (par.ff + dx[i] == cur.ff && par.ss + dy[i] == cur.ss) {
                path.pb(dir[i]);
                break;
            }
        }
        cur = par;
    }
    reverse(all(path));
    cout << path.size() << nl << path << nl;
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
