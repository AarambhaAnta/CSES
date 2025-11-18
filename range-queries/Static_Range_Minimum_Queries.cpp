#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

template <typename T>
class SegmentTree {
private:
    vector<T> tree;
    vector<T> arr;
    int n;

    T operation(T a, T b) {
        return min(a, b);
    }
    T identity() {
        return INF;
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
        }
    }
    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return identity();
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        T p1 = query(2 * node, start, mid, l, r);
        T p2 = query(2 * node + 1, mid + 1, end, l, r);
        return operation(p1, p2);
    }
    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    SegmentTree(vector<T>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }
    vector<T> getArray() {
        return arr;
    }
    void printTree() {
        cout << "Segment Tree: ";
        for (int i = 1; i < min(20, 4 * n); ++i) {
            cout << tree[i] << " ";
        }
        cout << "\n";
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    SegmentTree<int> st(A);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << st.query(a, b) << "\n";
    }

    return 0;
}