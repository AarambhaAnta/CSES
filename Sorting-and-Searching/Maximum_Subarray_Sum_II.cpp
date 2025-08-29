#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        A[i] += A[i - 1];
    }
    multiset<int> ms;
    for (int i = a; i < b; i++) {
        ms.insert(A[i]);
    }

    int ans = -INF;
    for (int i = 1; i <= n - a + 1; i++) {
        int j = i + b - 1;
        if (j <= n) {
            ms.insert(A[j]);
        }
        int sum = *ms.rbegin() - A[i-1];
        ans = max(ans, sum);
        j = i + a - 1;
        ms.erase(ms.find(A[j]));
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