#include <bits/stdc++.h>
using namespace std;

#define int long long
struct DS {
    multiset<int> lo, hi;
    int k, lo_s = lo.size(), hi_s = hi.size();
    DS(int k) : k(k) {}
    int get() {
        return *lo.rbegin();
    }
    void put(int x) {
        lo.insert(x);
        lo_s = lo.size();
        balance();
    }
    void release(int x) {
        auto lo_i = lo.find(x);
        auto hi_i = hi.find(x);
        if (lo_i != lo.end()) {
            lo.erase(lo_i);
        } else {
            hi.erase(hi_i);
        }
        lo_s = lo.size();
        hi_s = hi.size();
        balance();
    }
    void balance() {
        int med = (k + 1) / 2;
        while (lo_s > med) {
            auto lst = lo.rbegin();
            int last = *lst;
            lo.erase(prev(lo.end()));
            hi.insert(last);
            lo_s = lo.size();
            hi_s = hi.size();
        }
        while (lo_s < med && hi_s > 0) {
            auto fst = hi.begin();
            int first = *fst;
            hi.erase(fst);
            lo.insert(first);
            lo_s = lo.size();
            hi_s = hi.size();
        }
    }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int tail = 0, head = -1;
    DS window(k);
    vector<int> res;
    int len = 0;
    while (tail < n) {
        while (head + 1 < n && len < k) {
            ++head, ++len;
            window.put(A[head]);
        }
        if (len == k) {
            res.push_back(window.get());
        }
        if (tail > head) {
            ++tail;
            head = tail - 1;
        } else {
            window.release(A[tail]);
            --len, ++tail;
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