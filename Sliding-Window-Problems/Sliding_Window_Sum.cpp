#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<int> A(n);
    A[0] = x;
    for (int i = 1; i < n; i++) {
        A[i] = (a * A[i - 1] + b) % c;
    }

    int head = -1, tail = 0;
    int ans = 0;
    int cur_sum = 0;
    while (tail < n) {
        while (head + 1 < n && head - tail + 1 < k) {
            head++;
            cur_sum += A[head];
        }
        if (head - tail + 1 == k) {
            ans ^= cur_sum;
        }
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            cur_sum -= A[tail];
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