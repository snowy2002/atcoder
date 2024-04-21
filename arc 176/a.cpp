#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

void solve() {
    int cnt = 0;
    int n = read(), m = read();
    vector<pair<int, int>> a(m + 1);
    vector<pair<int, int>> ans;
    map<pair<int, int>, int> vis;
    for(int i = 1; i <= m; i++) {
        a[i].first = read() - 1;
        a[i].second = read() - 1;
        auto [x, y] = a[i];
        if(vis[{x, y}]) {
            cnt += 1;
            continue;
        }
        // vis[{x, y}] = 1;
        for(int i = 1; i <= n; i++) {
            ans.push_back({x, y});
            vis[{x, y}] = 1;
            x = (x + 1) % n;
            y = (y + 1) % n;
        }
    }
    for(int j = 0; j < n; j++) {
        if(cnt == 0) break;
        if(!vis[{0, j}]) {
            cnt --;
            int x = 0, y = j;
            for(int i = 1; i <= n; i++) {
                ans.push_back({x, y});
                vis[{x, y}] = 1;
                x = (x + 1) % n;
                y = (y + 1) % n;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

signed main() {
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    #else
        freopen("a.in", "r", stdin);
    #endif

    solve();
    return 0;
}