#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}
const int mod = 1e8;

void add(int &x, int y) {
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
}

void solve() {
    int n = read();
    vector<int> a(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
    }
    sort(a.begin() + 1, a.end());
    int r = n + 1;
    for(int i = 1; i <= n; i++) {
        // r = max(i + 1, r);
        while(r - 1 > i && a[i] + a[r - 1] >= 1e8) r -= 1;
        if(r <= i) r = i + 1;
        ans += a[i] * (n - 1);
        ans -= mod * (n + 1 - r);
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
    int f = 19990000;
    cout << 1e8  * f << "\n";

    solve();
    return 0;

}