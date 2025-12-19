#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
const int maxn = 505;
const ll inf = 2e18;

struct Edge {
    int to;
    ll cap;
    int rev;
};

vector<Edge> g[maxn];
int level[maxn], ptr[maxn];
bool reachable[maxn];

void addEdge(int u, int v, ll cap) {
    g[u].push_back({v, cap, (int)g[v].size()});
    g[v].push_back({u, 0, (int)g[u].size() - 1});
}

bool bfs(int s, int t) {
    fill(level, level + maxn, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : g[u]) {
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

ll dfs(int u, int t, ll pushed) {
    if (pushed == 0)
        return 0;
    if (u == t)
        return pushed;

    for (int& cid = ptr[u]; cid < (int)g[u].size(); cid++) {
        Edge& e = g[u][cid];
        if (e.cap > 0 && level[e.to] == level[u] + 1) {
            ll tr = dfs(e.to, t, min(pushed, e.cap));
            if (tr == 0) {
                continue;
            }
            e.cap -= tr;
            g[e.to][e.rev].cap += tr;
            return tr;
        }
    }
    return 0;
}

ll dinic(int s, int t) {
    ll flow = 0;
    while (bfs(s, t)) {
        fill(ptr, ptr + maxn, 0);
        while (ll pushed = dfs(s, t, inf)) {
            flow += pushed;
        }
    }
    return flow;
}

void reachable_from_source(int s) {
    fill(reachable, reachable + maxn, false);
    queue<int> q;
    q.push(s);
    reachable[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& e : g[u]) {
            if (e.cap > 0 && !reachable[e.to]) {
                reachable[e.to] = true;
                q.push(e.to);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 1);
        addEdge(v, u, 1);
        edges.push_back({u, v});
    }

    dinic(1, n);

    reachable_from_source(1);

    vector<pair<int, int>> cutEdges;
    for (auto [u, v] : edges) {
        if (reachable[u] && !reachable[v]) {
            cutEdges.push_back({u, v});
        }
        if (!reachable[u] && reachable[v]) {
            cutEdges.push_back({u, v});
        }
    }

    cout << cutEdges.size() << "\n";
    for (auto [u, v] : cutEdges) {
        cout << u << " " << v << "\n";
    }

    return 0;
}