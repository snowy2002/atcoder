#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

void solve() {
    int n = read(), m = read();
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 1; i <= m; i++) {
        int aa = read(), bb = read(), cc = read();
        g[aa].push_back({bb, -cc});
        g[bb].push_back({aa, cc});
    }

    vector<int> vis(n + 1), d(n + 1), f(n + 1);
    vector<vector<int>> p(n + 1);
    int mi = 1e18, id = 0, tot = 0;

    auto dfs = [&](auto dfs, int x) -> void {
        vis[x] = 1;
        p[tot].push_back(x);
        if(d[x] < mi) {
            mi = d[x];
            id = x;
        }
        for(auto [i, val] : g[x]) {
            if(vis[i]) continue;
            d[i] = d[x] + val;
            dfs(dfs, i);
        }
    };
    // return;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            tot += 1;
            mi = 1e18; d[i] = 0;
            dfs(dfs, i);
            int mask = 0;
            for(int j : p[tot]) {
                d[j] -= mi;
                mask |= (1 << d[j]);
            }
            f[tot] = mask;
        }
    }

    vector<int> ans(n + 1, -1ll);

    for(int i = 1; i <= tot; i++) {
        vector dp1(1 << n, 0ll);
        dp1[0] = 1;
        for(int j = 1; j <= tot; j++) {
            if(i == j) continue;
            vector dp2(1 << n, 0ll);
            for(int k = 0; k < (1 << n); k++) {
                if(!dp1[k]) continue;
                int res = f[j];
                while(res < (1 << n)) {
                    if((k & res) == 0) {
                        dp2[k | res] |= dp1[k];
                    }
                    res <<= 1;
                }
            }
            dp1 = dp2;
        }
        int res = f[i], cnt = 0, val = 1, v;
        while(res < (1 << n)) {
            if(dp1[((1 << n) - 1) ^ res]) {
                cnt += 1; v = val;
            }
            res <<= 1;
            val += 1;
        }
        if(cnt == 1) {
            for(int j : p[i]) {
                ans[j] = d[j] + v;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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