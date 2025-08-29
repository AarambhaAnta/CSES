#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    auto check = [&](int mi) -> bool {
        int cnt = 1;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            if (cur + A[i] <= mi) {
                cur += A[i];
            } else {
                cnt++;
                cur = A[i];
            }
        }
        return (cnt <= k);
    };
    int lo = *max_element(A.begin(), A.end()), hi = INF;
    int ans = INF;
    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;
        if (check(mi)) {
            ans = min(ans, mi);
            hi = mi - 1;
        } else {
            lo = mi + 1;
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