#include <bits/stdc++.h>
using namespace std;

#define int long long
struct State {
    int in, out, id;
    bool operator<(const State& s) const {
        return in < s.in;
    }
    friend istream& operator>>(istream& in, State& s) {
        in >> s.in >> s.out;
        return in;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<State> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i].id = i;
    }

    sort(A.begin(), A.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            cur++;
            ans[A[i].id] = cur;
            pq.push({A[i].out, cur});
        } else {
            auto x = pq.top();
            if (x.first < A[i].in) {
                pq.pop();
                ans[A[i].id] = x.second;
                pq.push({A[i].out, x.second});
            } else {
                cur++;
                ans[A[i].id] = cur;
                pq.push({A[i].out, cur});
            }
        }
    }
    cout << cur << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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