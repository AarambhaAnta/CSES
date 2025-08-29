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

    stack<int> idx;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        while (!idx.empty() && A[idx.top()] >= A[i]) {
            idx.pop();
        }
        pos[i] = (!idx.empty() ? idx.top() + 1 : 0);
        idx.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << pos[i] << " ";
    }
    cout << endl;
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