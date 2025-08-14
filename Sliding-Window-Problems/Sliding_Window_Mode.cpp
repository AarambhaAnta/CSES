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
    map<int, int> freq;
    map<int, set<int>> bucket;
    int len = 0;

    vector<int> res;
    while (tail < n) {
        while (head + 1 < n && len < k) {
            ++head;
            ++len;

            int f = freq[A[head]];
            freq[A[head]]++;
            if (f > 0) {
                bucket[f].erase(A[head]);
                if (bucket[f].empty()) {
                    bucket.erase(f);
                }
            }
            bucket[f + 1].insert(A[head]);
        }
        if (len == k) {
            res.push_back(*bucket.rbegin()->second.begin());
        }
        if (tail > head) {
            ++tail;
            head = tail - 1;
        } else {
            int f = freq[A[tail]];
            bucket[f].erase(A[tail]);
            if (bucket[f].empty()) {
                bucket.erase(f);
            }
            freq[A[tail]]--;
            if (freq[A[tail]] > 0) {
                bucket[f - 1].insert(A[tail]);
            } else {
                freq.erase(A[tail]);
            }

            --len;
            ++tail;
        }
    }
    for (int i = 0; i < (int)res.size(); i++) {
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