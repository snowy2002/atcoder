#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

void solve() {
    int n = read(), k = read();
    vector<int> a(n + 1), pos(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        pos[a[i]] = i;
    }
    set<int> s;
    for(int i = 1; i < k; i++) {
        s.insert(pos[i]);
    }
    int ans = n;
    for(int i = k; i <= n; i++) {
        s.insert(pos[i]);
        int r = *s.rbegin();
        int l = *s.begin();
        ans = min(ans, r - l);
        s.erase(pos[i - k + 1]);
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