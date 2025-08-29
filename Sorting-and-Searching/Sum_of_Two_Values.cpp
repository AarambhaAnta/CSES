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

    unordered_map<int, int> seen;
    seen.reserve(n * 1.3);
    for (int i = 0; i < n; i++) {
        int diff = x - A[i];
        if (seen.count(diff)) {
            cout << seen[diff] + 1 << " " << i + 1 << '\n';
            return;
        }
        seen[A[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
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