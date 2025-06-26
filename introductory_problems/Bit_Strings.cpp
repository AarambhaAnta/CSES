#include <iostream>
#include <vector>

#define vi vector<int>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

ll mod_exp(int base, int exponent, int mod) {
    ll result = 1;
    ll power = base;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * power) % mod;
        }
        power = (power * power) % mod;
        exponent >>= 1;
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    ll ans = mod_exp(2, n, MOD);
    cout << ans << '\n';
}
int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}