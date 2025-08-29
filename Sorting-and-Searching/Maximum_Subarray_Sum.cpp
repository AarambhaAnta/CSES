#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    int curr_sum = 0;
    int max_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (curr_sum + A[i] >= A[i]) {
            curr_sum += A[i];
        } else {
            curr_sum = A[i];
        }
        max_sum = max(max_sum, curr_sum);
    }
    cout << max_sum << '\n';
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