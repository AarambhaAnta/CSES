#include <iostream>
#include <vector>

#define vi vector<int>
#define ll long long
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}