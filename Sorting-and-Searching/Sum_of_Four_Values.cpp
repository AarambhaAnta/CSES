#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B[i] = i + 1;
    }
    sort(B.begin(), B.end(), [&](int i, int j) { return A[i - 1] < A[j - 1]; });
    sort(A.begin(), A.end());

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int lo = j + 1, hi = n - 1;
            while (lo < hi) {
                int sum = A[i] + A[j] + A[lo] + A[hi];
                if (x == sum) {
                    cout << B[i] << " " << B[j] << " " << B[lo] << " " << B[hi] << '\n';
                    return;
                } else if (x > sum) {
                    lo++;
                } else {
                    hi--;
                }
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