#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < m) {
        int diff = A[i] - B[j];
        if (abs(diff) <= k) {
            cnt++;
            i++;
            j++;
        } else if (diff > k) {
            j++;
        } else {
            i++;
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