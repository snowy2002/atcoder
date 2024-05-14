#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

void solve() {
    int n = read(), k = read();
    int ans = 0, now = k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(now >= a[i]) now -= a[i];
        else {
            now = k; now -= a[i];
            ans += 1;
        }
    }
    if(now != k) ans += 1;
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