#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

signed main() {
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    #else
        freopen("a.in", "r", stdin);
    #endif

    int n = 9, m = 8, ans = 0;
    for(int i = 1; i <= n; i++) {
        int a = read();
        ans += a;
    }
    for(int i = 1; i <= m; i++) {
        int a = read();
        ans -= a;
    }
    cout << ans + 1;
}