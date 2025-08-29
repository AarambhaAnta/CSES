#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    struct Range {
        int l, r;
        bool operator<(const Range& other) const {
            if(r==other.r)
                return l < other.l;
            return r < other.r;
        }
    };
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        int lo, hi;
        cin >> lo >> hi;
        ranges[i] = {lo, hi};
    }

    sort(ranges.begin(), ranges.end());

    int end = -1e9;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].l >= end) {
            cnt++;
            end = ranges[i].r;
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