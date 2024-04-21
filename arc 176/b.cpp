#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

int mod = 10;

int qpow(int a, int b) {
    // b = (b % (mod - 1) + mod - 1) % (mod - 1);
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n = read(), m = read(), k = read();
    // int val = m - k;
    if(n < k) {
        cout << qpow(2, n) << "\n";
        return;
    }
    int cnt = k;
    n -= k; m -= k;
    // if(n == 0)
    if(m == 1) {
        cout << 0 << "\n";
        return;
    }

    n %= m;
    cout << qpow(2, n + k) << "\n";
}

signed main() {
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    #else
        freopen("a.in", "r", stdin);
    #endif
    int t = read();
    while(t--) solve();
    return 0;
}