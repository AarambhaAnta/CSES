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
    ll cap, flow;
    int rev;
};

vector<Edge> g[maxn];
int level[maxn], ptr[maxn];

void addEdge(int u, int v, ll cap) {
    g[u].push_back({v, cap, 0, (int)g[v].size()});
    g[v].push_back({u, 0, 0, (int)g[u].size() - 1});
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
            if (e.cap - e.flow > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

ll dfs(int u, int t, ll pushed) {
    if (pushed == 0) {
        return 0;
    }
    if (u == t) {
        return pushed;
    }
    for (int& cid = ptr[u]; cid < (int)g[u].size(); cid++) {
        Edge& e = g[u][cid];
        if (e.cap - e.flow > 0 && level[e.to] == level[u] + 1) {
            ll tr = dfs(e.to, t, min(pushed, e.cap - e.flow));
            if (tr == 0) {
                continue;
            }
            e.flow += tr;
            g[e.to][e.rev].flow -= tr;
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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 1);
    }

    ll maxFlow = dinic(1, n);
    cout << maxFlow << '\n';

    vector<vector<int>> paths;

    for (int i = 0; i < maxFlow; i++) {
        vector<int> path;
        int cur = 1;
        path.push_back(cur);
        while (cur != n) {
            bool found = false;
            for (auto& e : g[cur]) {
                if (e.flow > 0 && e.to >= 1 && e.to <= n) {
                    e.flow = 0;
                    cur = e.to;
                    path.push_back(cur);
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        paths.push_back(path);
    }


    for (auto& path : paths) {
        cout << path.size() << '\n';
        for (auto& u : path) {
            cout << u << ' ';
        }
        cout << '\n';
    }

    return 0;
}