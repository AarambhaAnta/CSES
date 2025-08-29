#include <bits/stdc++.h>
using namespace std;
#define int long long

struct LineTree {
    struct TNode {
        int k, b;
        TNode *l, *r;
        TNode() : k(0), b(0), l(nullptr), r(nullptr) {}
    };

    TNode* root;
    int dl, dr;

    bool comp(int ak, int ab, int bk, int bb, int x) {
        return ak * x + ab > bk * x + bb;
    }

    void _modify(TNode*& p, int k, int b, int l, int r, int ml, int mr) {
        if (p == nullptr)
            p = new TNode();
        int mid = (l + r) / 2;
        if (ml <= l && r <= mr) {
            if (l == r) {
                if (comp(k, b, p->k, p->b, l))
                    p->k = k, p->b = b;
                return;
            }
            if (comp(k, b, p->k, p->b, mid))
                swap(p->k, k), swap(p->b, b);
            if (comp(k, b, p->k, p->b, l))
                _modify(p->l, k, b, l, mid, ml, mr);
            if (comp(k, b, p->k, p->b, r))
                _modify(p->r, k, b, mid + 1, r, ml, mr);
        } else {
            if (mid >= ml)
                _modify(p->l, k, b, l, mid, ml, mr);
            if (mid < mr)
                _modify(p->r, k, b, mid + 1, r, ml, mr);
        }
    }

    int _query(TNode*& p, int pos, int l, int r) {
        if (p == nullptr)
            return 0;
        if (l == r)
            return p->k * pos + p->b;
        int mid = (l + r) / 2;
        int ret = p->k * pos + p->b;
        if (pos <= mid)
            ret = max(ret, _query(p->l, pos, l, mid));
        else
            ret = max(ret, _query(p->r, pos, mid + 1, r));
        return ret;
    }

public:
    LineTree(int dl, int dr) : dl(dl), dr(dr), root(new TNode()) {}
    void modify(int k, int b, int l, int r) {
        if (l <= r)
            _modify(root, k, b, dl, dr, l, r);
    }
    int query(int pos) {
        return _query(root, pos, dl, dr);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, vector<int>> app;
    for (int i = 0; i < n; i++) {
        app[a[i]].push_back(i);
    }

    set<int> o;
    for (int i = -1; i <= n; i++) {
        o.insert(i);
    }

    LineTree lt(0, n);

    // Process heights in decreasing order
    vector<pair<int, vector<int>>> heights;
    for (auto& p : app) {
        heights.push_back({p.first, p.second});
    }
    sort(heights.rbegin(), heights.rend());

    for (auto [v, p] : heights) {
        for (auto i : p)
            o.erase(i);

        for (auto i : p) {
            auto it = o.upper_bound(i);
            int l = *prev(it) + 1;
            int r = *it - 1;

            if (r - k + 1 >= 0) {
                lt.modify(v, (k - l) * v, max(0LL, l - k + 1), min((long long)l, r - k + 1));
            }
            if (r - l + 1 >= k) {
                lt.modify(0, k * v, l, r - k + 1);
            }
            lt.modify(-v, (r + 1) * v, max((long long)l, r - k + 1), r);
            if (r - k + 1 <= l) {
                lt.modify(0, (r - l + 1) * v, r - k + 1, l);
            }
        }
    }

    for (int i = 0; i + k - 1 < n; i++) {
        cout << lt.query(i) << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}