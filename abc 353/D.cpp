#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}
const int mod = 998244353;

int cal(int x) {
    int cnt = 0;
    while(x) {
        cnt += 1;
        x /= 10;
    }
    return cnt;
}

void solve() {
    int n = read(), ans = 0;
    vector<int> a(n + 1), b(n + 2);
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) {
        b[i] = (int)pow(10, cal(a[i]));
        b[i] = b[i] % mod;
    }
    for(int i = n - 1; i >= 1; i--) {
        b[i] = b[i + 1] + b[i];
        b[i] = b[i] % mod;
    }
    for(int i = 1; i <= n; i++) {
        int v1 = b[i + 1] * a[i] % mod;
        int v2 = (i - 1) * a[i] % mod;
        ans += (v1 + v2) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}

signed main() {
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    #else
        //freopen("a.in", "r", stdin);
    #endif

    solve();
    return 0;
}