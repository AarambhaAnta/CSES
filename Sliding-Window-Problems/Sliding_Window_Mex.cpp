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
    set<int> mex;
    for (int i = 0; i < n; i++) {
        mex.insert(i);
    }

    map<int, int> freq;
    vector<int> res;
    while (tail < n) {
        while (head + 1 < n && len < k) {
            ++head, ++len;
            freq[A[head]]++;
            if (freq[A[head]] > 0) {
                mex.erase(A[head]);
            }
        }
        if (len == k) {
            res.push_back(*mex.begin());
        }
        if (tail > head) {
            ++tail;
            head = tail - 1;
        } else {
            freq[A[tail]]--;
            if (freq[A[tail]] <= 0) {
                mex.insert(A[tail]);
            }
            ++tail, --len;
        }
    }
    for (auto r : res) {
        cout << r << " ";
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