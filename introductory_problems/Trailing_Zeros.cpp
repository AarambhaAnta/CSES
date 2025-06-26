#include <iostream>
#include <vector>

#define vi vector<int>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        ans += n / 5;
        n /= 5;
    }
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