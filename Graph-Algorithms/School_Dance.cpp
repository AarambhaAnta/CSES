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
const int maxn = 1011;
const ll inf = 2e18;

struct Edge {
    int to;
    ll cap;
    int rev;
};

vector<Edge> g[maxn];
int level[maxn], ptr[maxn];

int addEdge(int u, int v, ll cap) {
    g[u].push_back({v, cap, (int)g[v].size()});
    g[v].push_back({u, 0, (int)g[u].size() - 1});

    return g[u].size() - 1;
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
    if (pushed == 0) {
        return 0;
    }
    if (u == t) {
        return pushed;
    }

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    // source = 0, destination = 1010;

    int boys, girls, possiblePairs, offset = 501;
    vector<tuple<int, int, int>> edgesList;

    cin >> boys >> girls >> possiblePairs;

    for (int boy = 1; boy <= boys; boy++) {
        addEdge(0, boy, 1);
    }


    for (int i = 0; i < possiblePairs; i++) {
        int boy, girl;
        cin >> boy >> girl;

        girl += offset;
        int idx = addEdge(boy, girl, 1);
        edgesList.push_back({boy, idx, girl});
    }

    for (int girl = 1; girl <= girls; girl++) {
        addEdge(girl + offset, 1010, 1);
    }

    dinic(0, 1010);

    vector<pair<int, int>> dancePair;
    for (auto& tup : edgesList) {
        int boy, idx, girl;
        tie(boy, idx, girl) = tup;

        Edge& e = g[boy][idx];
        if (e.cap == 0) {
            dancePair.push_back({boy, girl - offset});
        }
    }

    cout << dancePair.size() << '\n';
    for (auto [boy, girl] : dancePair) {
        cout << boy << " " << girl << '\n';
    }
    return 0;
}