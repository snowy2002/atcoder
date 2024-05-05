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
    vector<int> de(n + 1);
    for(int i = 1; i <= m; i++) {
        int aa = read(), bb = read(), cc = read();
        if(aa == bb) continue;
        g[bb].push_back({aa, cc});
        g[aa].push_back({bb, -cc});
        de[aa] += 1;
    }

    int state = 0;
    vector<int> d(n + 1), vis(n + 1);
    vector<int> id(n + 1);
    int nnn = 0, mi;
    auto dfs = [&](auto dfs, int x) -> void {
        vis[x] = 1;
        if(d[x] < mi) {
            mi = d[x];
            id[nnn] = x;
        }
        state = state + (1ll << d[x]);
        for(auto [i, val] : g[x]) {
            if(vis[i]) continue;
            d[i] = d[x] + val;
            dfs(dfs, i);
        }
    };

    vector<int> a;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            ++nnn;
            state = 0;
            d[i] = 16;
            mi = d[i]; id[nnn] = i; 
            dfs(dfs, i);
            // cout << i << "!!!\n";
            while(state % 2 == 0) state /= 2;
            a.push_back(state);
        }
    }
    int N = a.size();
    vector<int> an(n + 1);
    for(int i = 0; i < N; i++) {
        vector f1(1 << n + 1, 0ll);
        int tot = 0;
        f1[0] = 1;
        for(int j = 0; j < N; j++) {
            if(j == i) continue;
            int res = a[j];
            vector f2(1 << n + 1, 0ll);
            while(res <= (1 << n) - 1) {
                for(int k = 0; k < (1 << n); k++) {
                    if((k & res) != 0) continue;
                    if(!f1[k]) continue;
                    f2[k | res] |= f1[k];
                }
                res = res * 2;
            }
            f1 = f2;
        }
        
        int res = a[i], now = 1, ok = 0, ans = 0;
        while(res <= (1 << n) - 1) {
            if(f1[((1 << n) - 1) ^ res]) {
                if(!ans) ans = now, ok = 1;
                else ok = 0;
            }
            res <<= 1;
            now += 1;
        }
        if(ok) an[i] = ans;
    }

    vector<int> aa(n + 1);
    auto dfs1 = [&](auto dfs1, int x, int pd) -> void {
        aa[x] = pd;
        vis[x] = 1;
        for(auto [i, val] : g[x]) {
            if(vis[i]) continue;
            if(pd == -1) dfs1(dfs1, i, pd);
            else dfs1(dfs1, i, pd + val);
        }
    };

    int cnt = 0;
    vector<int> v(n + 1);
    vis = v;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            if(an[cnt] == 0) {
                dfs1(dfs1, i, -1);
            }
            else {
                dfs1(dfs1, id[cnt + 1], an[cnt]);
            }
            cnt += 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << aa[i] << " ";
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