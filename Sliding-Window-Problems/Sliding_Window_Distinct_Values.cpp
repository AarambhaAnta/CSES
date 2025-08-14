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
    int len = 0;
    int dis = 0;
    map<int, int> freq;
    vector<int> res;
    while (tail < n) {
        while (head + 1 < n && len < k) {
            ++head;
            if (freq[A[head]] == 0) {
                ++dis;
            }
            freq[A[head]]++;
            ++len;
        }
        if (len == k) {
            res.push_back(dis);
        }
        if (tail > head) {
            ++tail;
            head = tail - 1;
        } else {
            freq[A[tail]]--;
            if (freq[A[tail]] == 0) {
                freq.erase(A[tail]);
                --dis;
            }
            --len;
            ++tail;
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
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