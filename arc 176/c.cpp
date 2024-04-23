#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}
const int mod = 998244353;

void solve() {
    int n = read(), m = read();
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> de(n + 1);
    for(int i = 1; i <= m; i++) {
        int aa = read(), bb = read(), val = read();
        g[val].push_back({aa, bb});
        de[aa] += 1;
        de[bb] += 1;
    }
    int cnt = 0;
    vector<int> f(n + 2), vis(n + 1);
    for(int i = 1; i <= n; i++) {
        if(!de[i]) f[n + 1] += 1;
    }
    int ans = 1;
    for(int i = n; i >= 1; i--) {
        if(g[i].size() == 0) continue;
        if(g[i].size() == 1) {
            auto [aa, bb] = g[i][0];
            if(de[aa] != 1 && de[bb] != 1) {
                cout << 0 << "\n";
                // cout << "!!\n";
                return;
            }
            if(de[aa] == 1 && de[bb] == 1) {
                ans = ans * 2 % mod;
                de[aa] -= 1;
                de[bb] -= 1;
                vis[i] = 1;
                f[i] = 1;
                continue;
            }
            if(de[aa] == 1 || de[bb] == 1) {
                de[aa] -= 1;
                de[bb] -= 1;
                vis[i] = 1;
            }
        }
        else {
            map<int, int> v;
            for(auto [aa, bb] : g[i]) {
                v[aa] += 1;
                v[bb] += 1;
                de[aa] -= 1;
                de[bb] -= 1;
            }
            auto [aa, bb] = g[i][0];
            int ma = (v[aa] > v[bb]) ? aa : bb;
            if(v[ma] != g[i].size() || de[ma] != 0) {
                cout << 0 << "\n";
                return;
            }
            for(auto [aa, bb] : g[i]) {
                int cc = aa + bb - ma;
                if(de[cc] == 0) {
                    f[i] += 1;
                }
            }
            vis[i] = 1;
        }
    }
    int now = 0;
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j <= f[i]; j++) {
            ans = ans * now % mod;
            now -= 1;
        }
        if(!vis[i]) now += 1;
    }
    for(int i = 1; i <= cnt; i++) {
        ans = ans * i % mod;
    }
    cout << ans << "\n";
}

signed main() {
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    #else
        // freopen("a.in", "r", stdin);
    #endif
    solve();
    return 0;
}