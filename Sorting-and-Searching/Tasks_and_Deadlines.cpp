#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
        ans += A[i].second;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++)
    {
        ans -= (n - i) * A[i].first;
    }
    cout << ans << endl;
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