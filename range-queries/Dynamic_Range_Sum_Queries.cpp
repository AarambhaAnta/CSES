#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) (x).begin(), (x).end()
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
const ll inf = 2e18;
vector<ll> segArr, A;

void init(int n) {
    segArr = vector<ll>(4 * n + 4);
    A = vector<ll>(n + 1);
}

void build(int node, int start, int end) {
    if (start == end) {
        segArr[node] = A[start];
        return;
    }
    int mid = (start + end) / 2;
    // left
    build(2 * node, start, mid);
    // right
    build(2 * node + 1, mid + 1, end);
    // merge
    segArr[node] = segArr[2 * node] + segArr[2 * node + 1];
}

void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        A[idx] = val;
        segArr[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        // left
        update(2 * node, start, mid, idx, val);
    } else {
        // right
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    // merge
    segArr[node] = segArr[2 * node] + segArr[2 * node + 1];
}

ll query(int node, int start, int end, int lq, int rq) {
    if (start >= lq && end <= rq) {
        return segArr[node];
    }
    if (start > rq || end < lq) {
        return 0;
    }
    int mid = (start + end) / 2;
    // left
    ll lVal = query(2 * node, start, mid, lq, rq);
    // right
    ll rVal = query(2 * node + 1, mid + 1, end, lq, rq);
    // merge
    return lVal + rVal;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    init(n);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    build(1, 1, n);

    int type, l, r, idx;
    ll val;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }


    return 0;
}