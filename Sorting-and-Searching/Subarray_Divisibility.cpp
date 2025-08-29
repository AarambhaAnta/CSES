#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    int cur = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        cur += A[i];
        int r = (cur % n + n) % n;
        cnt += mp[r]++;
    }
    cout << cnt << endl;
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