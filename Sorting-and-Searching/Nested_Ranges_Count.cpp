#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered set template
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
struct State {
    int l, r, idx, contains, contained;
    bool operator<(const State& o) const {
        return idx < o.idx;
    }
    friend istream& operator>>(istream& in, State& s) {
        in >> s.l >> s.r;
        return in;
    }
    friend ostream& operator<<(ostream& out, State& s) {
        out << s.l << " " << s.r << " " << s.contains << " " << s.contained << '\n';
        return out;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<State> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i].idx = i;
    }

    auto comp = [&](State& s1, State& s2) -> bool {
        return (s1.l == s2.l ? s1.r > s2.r : s1.l < s2.l);
    };
    sort(A.begin(), A.end(), comp);
    ordered_set<pair<int, int>> os;
    for (int i = n - 1; i >= 0; --i) {
        os.insert({A[i].r, -1 * i});
        int cnt = os.order_of_key({A[i].r, -1 * i});
        A[i].contains = cnt;
    }
    os.clear();
    for (int i = 0; i < n; i++) {
        os.insert({A[i].r, -1 * i});
        int cnt = os.order_of_key({A[i].r, -1 * i});
        A[i].contained = os.size() - cnt - 1;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++) {
        cout << A[i].contains << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i].contained << " ";
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