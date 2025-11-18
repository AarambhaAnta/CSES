#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

// initial
int n, m;
vector<string> g;
int current_rooms = 0;
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

// helpers
bool is_valid(int nx, int ny) {
    return nx >= 0 && ny >= 0 && nx < n && ny < m;
}
void dfs(int x, int y) {
    g[x][y] = 'm';
    for (int i = 0; i < 4; i++) {
        int nx = x + row[i], ny = y + col[i];
        if (is_valid(nx, ny) && g[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

void solve() {
    // input
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    // process
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                current_rooms++;
                dfs(i, j);
            }
        }
    }

    // output
    cout << current_rooms << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}