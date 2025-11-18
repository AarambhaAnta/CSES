#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (i != 0) {
            A[i] += A[i - 1];
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int v = A[b] - (a - 1 >= 0 ? A[a - 1] : 0);
        cout << v << endl;
    }
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