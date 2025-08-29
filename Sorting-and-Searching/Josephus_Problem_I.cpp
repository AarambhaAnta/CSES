#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    bool sw = true;
    while (!dq.empty()) {
        if(sw){
            dq.push_back(dq.front());
        }else{
            cout << dq.front() << " ";
        }
        dq.pop_front();
        sw = !sw;
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