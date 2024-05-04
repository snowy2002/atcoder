#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

int xx[] = {0, 1, 0, -1, 0};
int yy[] = {0, 0, 1, 0, -1};



void solve() {
    int n = read(), m = read();
    auto ok = [&](int x, int y) {
        if(x >= 1 && x <= n && y >= 1 && y <= m) return 1;
        return 0;
    };
    vector a(n + 1, vector(m + 1, 'a'));
    vector vis(n + 1, vector(m + 1, 0ll));
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            // if(a[i][j] == '.') ans = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= 4; k++) {
                int ni = i + xx[k];
                int nj = j + yy[k];
                if(ok(ni, nj) && a[ni][nj] == '#' && a[i][j] == '.') {
                    a[i][j] = '1';
                }
            }
            // cout << a[i][j] << " \n"[j == m];
        }
    }
    int res = 0;
    auto bfs = [&](int x, int y) -> void {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        vector<pair<int, int>> F;
        // cout << x << " " << y << "!!\n";
        // res = 1;
        while(q.size()) {
            auto [x1, y1] = q.front(); q.pop();
            // vis[x1][y1] = 1;
            res += 1;
            if(a[x1][y1] == '1') F.push_back({x1, y1});
            if(a[x1][y1] == '1') continue; 
            for(int k = 1; k <= 4; k++) {
                int nx = x1 + xx[k];
                int ny = y1 + yy[k];
                if(ok(nx, ny) && !vis[nx][ny] && a[nx][ny] != '#') {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            } 
        }
        for(auto [x, y] : F) {
            vis[x][y] = 0;
        }
    };

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != '.') continue;
            if(vis[i][j]) continue;
            res = 0;
            bfs(i, j);
            ans = max(ans, res);
        }
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
}