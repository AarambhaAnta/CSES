#include <bits/stdc++.h>
using namespace std;

#define int long long
struct DS {
    multiset<int> lo, hi;
    int sum_l = 0, sum_r = 0;
    int lo_s = 0, hi_s = 0;
    int k = 0;
    int cost = 0;

    DS(int k) : k(k) {}
    int get_cost() {
        return cost;
    }
    void put(int x) {
        lo.insert(x);
        lo_s = lo.size();
        sum_l += x;
        balance();
    }
    void release(int x) {
        auto lo_it = lo.find(x);
        auto hi_it = hi.find(x);
        if (lo_it != lo.end()) {
            sum_l -= *lo_it;
            lo.erase(lo_it);
        } else {
            sum_r -= *hi_it;
            hi.erase(hi_it);
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
            sum_l -= last;
            sum_r += last;
        }
        while(lo_s<med && hi_s>0){
            auto fst = hi.begin();
            int first = *fst;
            hi.erase(hi.begin());
            lo.insert(first);
            lo_s = lo.size();
            hi_s = hi.size();
            sum_l += first;
            sum_r -= first;
        }
        int median = 0;
        if (!lo.empty()) {
            median = *lo.rbegin();
        }
        cost = (lo_s * median - sum_l) + (sum_r - hi_s * median);
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
    int len = 0;
    DS window(k);
    vector<int> res;
    while (tail < n) {
        while (head + 1 < n && len < k) {
            ++head, ++len;
            window.put(A[head]);
        }
        if (len == k) {
            res.push_back(window.get_cost());
        }
        if (tail > head) {
            ++tail;
            head = tail - 1;
        } else {
            window.release(A[tail]);
            --len, ++tail;
        }
        // cout << tail << "->" << head << endl;
    }
    for (int r : res) {
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