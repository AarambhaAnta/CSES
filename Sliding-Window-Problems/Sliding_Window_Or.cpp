#include <bits/stdc++.h>
using namespace std;

#define int long long

struct STATE_DS {
    stack<pair<int, int>> front, back;
    void push(int x) {
        int top_or = (back.empty() ? 0 : back.top().second);
        back.push({x, x | top_or});
    }
    void pop() {
        if (front.empty()) {
            while (!back.empty()) {
                int val = back.top().first;
                back.pop();
                int top_or = (front.empty() ? 0 : front.top().second);
                front.push({val, val | top_or});
            }
        }
        if (!front.empty()) {
            front.pop();
        }
    }
    int get() const {
        int or1 = (front.empty() ? 0 : front.top().second);
        int or2 = (back.empty() ? 0 : back.top().second);
        return or1 | or2;
    }
    int size() {
        return front.size() + back.size();
    }
};


void solve() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    int tail = 0, head = -1;
    STATE_DS window;
    int cur = x;
    int ans = 0;
    while (tail < n) {
        while (head + 1 < n && window.size() < k) {
            head++;
            window.push(cur);
            cur = (a * cur + b) % c;
        }
        if (window.size() == k) {
            ans ^= window.get();
        }
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            window.pop();
            tail++;
        }
    }
    cout << ans << endl;
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