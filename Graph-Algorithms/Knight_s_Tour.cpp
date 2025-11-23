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
const int N = 8;
int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int board[N][N];

inline bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

int countMoves(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inside(nx, ny) && board[nx][ny] == 0) {
            cnt++;
        }
    }
    return cnt;
}

bool dfs(int x, int y, int steps) {
    board[x][y] = steps;

    if (steps == N * N)
        return true;

    vector<tuple<int, int, int>> nextCells;
    for (int i = 0; i < N; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (inside(nx, ny) && board[nx][ny] == 0) {
            int moves = countMoves(nx, ny);
            nextCells.push_back({moves, nx, ny});
        }
    }
    sort(all(nextCells));

    for (auto [m, nx, ny] : nextCells) {
        if (dfs(nx, ny, steps + 1))
            return true;
    }

    board[x][y] = 0;
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    --x, --y;
    dfs(y, x, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << (j + 1 == N ? "\n" : " ");
        }
    }

    return 0;
}