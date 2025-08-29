#include <bits/stdc++.h>
using namespace std;
#define int long long

struct BIT {
    int n;
    vector<int> bit;
    BIT() : n(0) {}
    BIT(int n) : n(n), bit(n + 1, 0) {}
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    int sum_prefix(int idx) {
        int r = 0;
        for (; idx > 0; idx -= idx & -idx) {
            r += bit[idx];
        }
        return r;
    }
    int sum_range(int l, int r) {
        if (r < l) {
            return 0;
        }
        return sum_prefix(r) - sum_prefix(l - 1);
    }
};
struct DS {
    BIT bit;
    int window_size = 0;
    int inversion = 0;
    DS() {};
    DS(int m) {
        bit.init(m);
    }
    void init(int m) {
        bit.init(m);
        window_size = 0;
        inversion = 0;
    }
    void insert(int x) {
        int greater = window_size - bit.sum_prefix(x);
        inversion += greater;
        bit.add(x, 1);
        ++window_size;
    }
    void erase(int x) {
        int smaller = bit.sum_prefix(x - 1);
        inversion -= smaller;
        bit.add(x, -1);
        --window_size;
    }
    int get_inversion() const {
        return inversion;
    }
};
vector<int> compress(const vector<int>& A) {
    vector<int> comp = A;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    return comp;
}
int get_id(int x, const vector<int>& comp) {
    return (int)(lower_bound(comp.begin(), comp.end(), x) - comp.begin()) + 1;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> comp = compress(A);
    int M = (int)comp.size();
    vector<int> ids(n);
    for (int i = 0; i < n; i++) {
        ids[i] = get_id(A[i], comp);
    }

    int tail = 0, head = -1;
    int len = 0;
    DS window(M);
    vector<int> res;
    res.reserve(max(0ll, n - k + 1));
    while (tail < n) {
        while (head + 1 < n && len < k) {
            ++head, ++len;
            window.insert(ids[head]);
        }
        if (len == k) {
            res.push_back(window.get_inversion());
        }
        if (tail > head) {
            ++tail;
            head = tail - 1;
        } else {
            window.erase(ids[tail]);
            ++tail, --len;
        }
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