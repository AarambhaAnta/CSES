#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[i] = i + 1;
    }
    sort(B.begin(), B.end(), [&](int a, int b) { return A[a - 1] < A[b - 1]; });
    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            if (x == A[i] + A[lo] + A[hi]) {
                cout << B[i] << " " << B[lo] << " " << B[hi] << '\n';
                return;
            } else if (x > A[i] + A[lo] + A[hi]) {
                lo++;
            } else {
                hi--;
            }
        }
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