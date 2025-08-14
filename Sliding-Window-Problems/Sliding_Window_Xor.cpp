#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    queue<int> q;
    auto get_i = [&](int i) -> int {
        if (i==0) {
            return x;
        }
        return (a * q.back() + b) % c;
    };
    int tail = 0, head = -1;
    int ans = 0;
    int cur_xor = 0;
    while (tail < n) {
        while (head + 1 < n && head - tail + 1 < k) {
            head++;
            cur_xor ^= get_i(head);
            q.push(get_i(head));
        }
        if (head - tail + 1 == k) {
            ans ^= cur_xor;
        }
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            cur_xor ^= q.front();
            q.pop();
            tail++;
        }
    }
    cout << ans << '\n';
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