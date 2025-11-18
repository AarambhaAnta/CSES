#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
// #define int long long

// initial
int n, m;
vector<string> g;
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};
const int inf = 1e9;

// helper
vector<vector<int>> dis;
vector<vector<pair<int, int>>> par;

bool is_valid(int nx, int ny) {
    return nx >= 0 && ny >= 0 && nx < n && ny < m;
}
void bfs(pair<int, int> src) {
    dis[src.first][src.second] = 0;
    par[src.first][src.second] = {-1, -1};
    queue<pair<int, int>> q;
    q.push(src);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + row[i], ny = y + col[i];
            if (is_valid(nx, ny) && g[nx][ny] != '#' && dis[nx][ny] > dis[x][y] + 1) {
                dis[nx][ny] = dis[x][y] + 1;
                par[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}
void solve() {
    // input
    cin >> n >> m;
    g.resize(n);
    pair<int, int> src, des;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        size_t sj = g[i].find('A'), dj = g[i].find('B');
        if (sj != string::npos) {
            src = {i, sj};
        }
        if (dj != string::npos) {
            des = {i, dj};
        }
    }

    // process
    dis = vector<vector<int>>(n, vector<int>(m, inf));
    par = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, {-1, -1}));
    bfs(src);

    // output
    if (dis[des.first][des.second] == inf) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    cout << dis[des.first][des.second] << nl;
    string res;
    pair<int, int> cur = des;
    while (cur != src) {
        pair<int, int> p = par[cur.first][cur.second];
        for (int i = 0; i < 4; i++) {
            if (make_pair(p.first + row[i], p.second + col[i]) == cur) {
                res.push_back(dir[i]);
                cur = p;
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << res << nl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}