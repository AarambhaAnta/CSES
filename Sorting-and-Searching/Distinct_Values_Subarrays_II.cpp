#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int tail = 0, head = -1;

    map<int, int> mp;
    int disCnt = 0;

    int cnt = 0;
    while (tail < n) {
        while (head + 1 < n && (disCnt < k || mp[A[head + 1]] != 0)) {
            head++;
            if (mp[A[head]] == 0)
                disCnt++;
            mp[A[head]]++;
        }
        cnt += (head - tail + 1);
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            mp[A[tail]]--;
            if (mp[A[tail]] == 0)
                disCnt--;
            tail++;
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