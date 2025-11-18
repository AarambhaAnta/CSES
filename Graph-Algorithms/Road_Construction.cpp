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
const int maxn = 2e5 + 5;

int n, m;
vector<pair<int, int>> edges;
int parent[maxn], d_rank[maxn];
int set_size = -1;
multiset<int> st;

void make_set(int x) {
    parent[x] = x;
    d_rank[x] = 1;
    st.insert(1);
}

int find_set(int x) {
    if (x != parent[x]) {
        return parent[x] = find_set(parent[x]);
    }
    return x;
}

void merge(int x, int y) {
    x = find_set(x), y = find_set(y);
    if (x != y) {
        st.erase(st.find(d_rank[x]));
        st.erase(st.find(d_rank[y]));

        if (d_rank[x] >= d_rank[y]) {
            parent[y] = x;
            d_rank[x] += d_rank[y];
            st.insert(d_rank[x]);
        } else {
            parent[x] = y;
            d_rank[y] += d_rank[x];
            st.insert(d_rank[y]);
        }
        set_size--;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    set_size = n;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    for (auto [a, b] : edges) {
        merge(a, b);
        cout << set_size << " " << *st.rbegin() << '\n';
    }
    return 0;
}