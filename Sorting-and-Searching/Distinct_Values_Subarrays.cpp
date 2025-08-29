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
    set<int> st;
    int tail = 0, head = -1;
    int ans = 0;
    while (tail < n) {
        while (head + 1 < n && !st.count(A[head + 1])) {
            head++;
            st.insert(A[head]);
        }
        ans += (head - tail) * (head - tail + 1) / 2;
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            st.erase(A[tail]);
            tail++;
        }
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