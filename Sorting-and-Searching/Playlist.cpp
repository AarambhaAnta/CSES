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
    deque<int> dq;
    size_t len = 1;

    for (int i = 0; i < n; i++) {
        if (st.count(A[i])) {
            while (!dq.empty()) {
                int top = dq.front();
                dq.pop_front();
                st.erase(st.find(top));
                if (top == A[i]) {
                    break;
                }
            }
        }
        st.insert(A[i]);
        dq.push_back(A[i]);
        len = max(len, st.size());
    }
    cout << len << '\n';
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