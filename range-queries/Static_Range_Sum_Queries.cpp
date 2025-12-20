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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> A(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // prefix sum
    for (int i = 1; i <= n; i++) {
        A[i] += A[i - 1];
    }

    int l, r;
    ll sum;
    while (q--) {
        cin >> l >> r;

        sum = A[r] - A[l - 1];
        cout << sum << '\n';
    }


    return 0;
}