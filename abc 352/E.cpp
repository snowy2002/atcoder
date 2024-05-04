#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

struct node {
    int num, c;
    vector<int> ver;
};

void solve() {
    int n = read(), m = read();
    vector<node> e(m + 1);
    for(int i = 1; i <= m; i++) {
        e[i].num = read(); e[i].c = read();
        for(int j = 1; j <= e[i].num; j++) {
            int x = read();
            e[i].ver.push_back(x);
        }
    }

    vector<int> f(n + 1);
    for(int i = 1; i <= n; i++) f[i] = i;

    auto fi = [&](auto fi, int x) -> int {
        if(x != f[x]) f[x] = fi(fi, f[x]);
        return f[x];
    };

    sort(e.begin() + 1, e.end(), [&](node a, node b) {
        return a.c < b.c;
    });

    int cnt = 1, ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j < e[i].ver.size(); j++) {
            int aa = e[i].ver[j - 1];
            int bb = e[i].ver[j];
            int fa = fi(fi, aa);
            int fb = fi(fi, bb);
            if(fa != fb) {
                cnt += 1;
                f[fa] = fb;
                ans += e[i].c;
            }
            if(cnt == n) break;
        }
        if(cnt == n) break;
    }
    if(cnt == n) {
        cout << ans << "\n";
    }
    else cout << "-1\n";
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