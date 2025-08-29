#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered set template
// Use less_equal<T> for multiset behavior
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Functions:
// os.find_by_order(k) - returns iterator to the k-th element (0-based index)
// os.order_of_key(x) - returns the number of elements strictly less than x

// Example usage:
// ordered_set<int> os;
// os.insert(10);
// os.insert(20);
// cout << *os.find_by_order(0) << '\n'; // 10
// cout << os.order_of_key(15) << '\n'; // 1

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    iota(A.begin(), A.end(), 1ll);

    ordered_set<int> os(A.begin(), A.end());

    int i = 0;
    int sz = os.size();
    while(sz>0){
        i = (i + k) % sz;
        auto it = os.find_by_order(i);
        cout << *it << " ";
        os.erase(it);
        sz = os.size();
    }
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