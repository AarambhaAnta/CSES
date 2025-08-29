#include <bits/stdc++.h>
using namespace std;

#define int long long
struct State {
    int l, r;
    int idx;
    bool contains, contained;
};

void solve() {
    int n;
    cin >> n;
    vector<State> A(n);
    for (int i = 0; i < n; i++) {
        int lo, hi;
        cin >> lo >> hi;
        A[i].l = lo;
        A[i].r = hi;
        A[i].idx = i;
    }
    auto sort1 = [&](const State& s1, const State& s2) {
        if (s1.l == s2.l)
            return s1.r >= s2.r;
        return s1.l < s2.l;
    };

    auto sort2 = [&](const State& s1, const State& s2) {
        if (s1.r == s2.r)
            return s1.l >= s2.l;
        return s1.r < s2.r;
    };

    auto sort3 = [&](const State& s1, const State& s2) { return s1.idx < s2.idx; };

    sort(A.begin(), A.end(), sort1);
    int rMax = A[0].r;
    A[0].contained = 0;
    for (int i = 1; i < n; i++) {
        A[i].contained = (A[i].r <= rMax);
        rMax = max(rMax, A[i].r);
    }

    sort(A.begin(), A.end(), sort2);
    int lMax = A[0].l;
    A[0].contains = 0;
    for (int i = 1; i < n; i++) {
        A[i].contains = (lMax >= A[i].l);
        lMax = max(lMax, A[i].l);
    }

    sort(A.begin(), A.end(), sort3);

    for (int i = 0; i < n; i++) {
        cout << A[i].contains << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << A[i].contained << " ";
    }
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