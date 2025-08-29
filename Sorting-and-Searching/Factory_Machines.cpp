#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18 + 10;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    auto check = [&](int x) -> bool {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += (x / A[i]);
            if(cur>=t)
                return true;
        }
        return false;
    };

    int lo = 0, hi = *max_element(A.begin(),A.end())*t;
    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;
        if (check(mi)) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    cout << lo << endl;
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