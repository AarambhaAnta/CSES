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

    int cur = 0;
    map<int, int> ump;
    ump[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cur += A[i];
        cnt += (ump.count(cur - x) ? ump[cur - x] : 0);
        ump[cur]++;
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