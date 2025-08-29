#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int tail = 0, head = -1;
    int cnt = 0;
    int cur = 0;
    while (tail < n) {
        while (head + 1 < n && cur + A[head + 1] <= x) {
            head++;
            cur += A[head];
        }
        cnt += (cur == x);
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            cur -= A[tail];
            tail++;
        }
    }
    cout << cnt << '\n';
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