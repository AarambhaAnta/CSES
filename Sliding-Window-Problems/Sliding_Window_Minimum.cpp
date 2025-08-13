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

    int tail = 0, head = -1;
    int ans = 0;
    deque<int> dq;
    while (tail < n) {
        while (head + 1 < n && head - tail + 1 < k) {
            head++;
            while (!dq.empty() && A[dq.back()] >= A[head]) {
                dq.pop_back();
            }
            dq.push_back(head);
        }
        if (head - tail + 1 == k) {
            ans ^= A[dq.front()];
        }
        if (tail > head) {
            tail++;
            head = tail - 1;
            dq.clear();
        } else {
            if (A[tail] == A[dq.front()]) {
                dq.pop_front();
            }
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