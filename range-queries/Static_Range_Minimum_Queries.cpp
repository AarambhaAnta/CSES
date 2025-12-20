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

class SegTree {
private:
    vector<ll> segArr;
    vector<ll>* A;

public:
    SegTree(int n, vector<ll>* ptr) {
        segArr = vector<ll>(4 * n);
        A = ptr;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            segArr[node] = (*A)[start];
            return;
        }
        int mid = (start + end) / 2;
        // left
        build(2 * node, start, mid);
        // right
        build(2 * node + 1, mid + 1, end);
        // merge
        segArr[node] = min(segArr[2 * node], segArr[2 * node + 1]);
    }

    ll query(int node, int start, int end, int lq, int rq) {
        if (start >= lq && end <= rq) {
            return segArr[node];
        }
        if (start > rq || end < lq) {
            return inf;
        }

        int mid = (start + end) / 2;

        // left-right->merge
        return min(query(2 * node, start, mid, lq, rq), query(2 * node + 1, mid + 1, end, lq, rq));
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    SegTree st(n + 1, &A);
    st.build(1, 1, n);

    int l, r;
    while (q--) {
        cin >> l >> r;
        ll minVal = st.query(1, 1, n, l, r);
        cout << minVal << '\n';
    }

    return 0;
}