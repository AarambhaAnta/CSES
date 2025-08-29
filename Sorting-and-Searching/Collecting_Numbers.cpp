#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> val(n + 1), pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        pos[val[i]] = i;
    }
    int inverstion = 1;
    for (int i = 2; i <= n; i++) {
        inverstion += (pos[i] < pos[i - 1]);
    }
    cout << inverstion;
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