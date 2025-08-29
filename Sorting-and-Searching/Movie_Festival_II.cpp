#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
struct State {
    int l, r;
    bool operator<(const State& o) const {
        return r < o.r;
    }
    friend istream& operator>>(istream& in, State& s) {
        in >> s.l >> s.r;
        return in;
    }
    friend ostream& operator<<(ostream& out, const State& s) {
        out << s.l << " " << s.r << '\n';
        return out;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<State> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    multiset<int> ms;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ms.empty()) {
            ms.insert(A[i].r);
            cnt++;
        } else {
            auto lb = ms.lower_bound(A[i].l);
            if (lb == ms.begin()) {
                if (*lb == A[i].l) {
                    ms.erase(lb);
                    ms.insert(A[i].r);
                    cnt++;
                } else if ((int)ms.size() < k) {
                    ms.insert(A[i].r);
                    cnt++;
                }
            } else if (lb == ms.end()) {
                --lb;
                ms.erase(lb);
                ms.insert(A[i].r);
                cnt++;
            } else {
                if (*lb == A[i].l) {
                    ms.erase(lb);
                    ms.insert(A[i].r);
                    cnt++;
                } else {
                    --lb;
                    ms.erase(lb);
                    ms.insert(A[i].r);
                    cnt++;
                }
            }
        }
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