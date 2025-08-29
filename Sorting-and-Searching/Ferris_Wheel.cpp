#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int tail = 0, head = n - 1;
    int cnt = 0;
    while (tail <= head) {
        int sum = A[tail] + A[head];
        if (sum <= x) {
            cnt++;
            tail++;
            head--;
        } else  {
            if (A[head] <= x) {
                cnt++;
            }
            head--;
        }
    }

    // if(head>=tail && A[tail]<=x)
    //     cnt++;

    cout << cnt << '\n';
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