#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int in, out;
        cin >> in >> out;
        A[i] = {in, out};
    }

    sort(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    size_t cnt = 0;
    for (int i = 0; i < n; i++) {
        int in = A[i].first, out = A[i].second;
        while (!pq.empty() && pq.top() < in) {
            pq.pop();
        }
        pq.push(out);
        cnt = max(cnt, pq.size());
    }
    cout << cnt << '\n';
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