#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    queue<pair<int, int>> q;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};
    int inf = 1e9;
    pair<int, int> src = {-1, -1};
    optional<pair<int, int>> des;
    vector<vector<int>> mDis(n, vector<int>(m, inf)), pDis(n, vector<int>(m, inf));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> last_char(n, vector<char>(m));

    auto is_valid = [&](int nx, int ny) -> bool { return nx >= 0 && ny >= 0 && nx < n && ny < m; };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                mDis[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                src = {i, j};
                pDis[i][j] = 0;
            }
        }
    }
    // Monsters

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_valid(nx, ny) && grid[nx][ny] != '#') {
                if (mDis[nx][ny] > mDis[x][y] + 1) {
                    mDis[nx][ny] = mDis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    // Person
    q.push(src);
    while (!q.empty()) {
        auto [x, y] = q.front();
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
            if (pDis[x][y] < mDis[x][y]) {
                des = {x, y};
                break;
            }
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_valid(nx, ny) && grid[nx][ny] != '#') {
                if (pDis[nx][ny] > pDis[x][y] + 1) {
                    pDis[nx][ny] = pDis[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    last_char[nx][ny] = dir[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    if (!des) {
        cout << "NO\n";
        return 0;
    }

    string s = "";
    pair<int, int> cur = *des;
    while(cur!=src){
        auto [x, y] = cur;
        s += last_char[x][y];
        cur = parent[x][y];
    }
    reverse(all(s));
    cout << "YES\n" << s.size() << '\n' << s << endl;
    return 0;
}