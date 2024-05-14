#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

struct node {
    int x, y, val;
};

void solve() {
    int k = read();
    int sx = read(), sy = read();
    int tx = read(), ty = read();

    int tp1 = (sx / k) + (sy / k);
    int tp2 = (tx / k) + (ty / k);

    vector<node> f1, f2;

    if((tp1 & 1) == 0) {
        int x = sx / k, y = sy / k;
        f1.push_back({x + 1, y, k - sx % k});
        f1.push_back({x - 1, y, sx % k + 1});
        f1.push_back({x, y + 1, k - sy % k});
        f1.push_back({x, y - 1, sy % k + 1});
    }
    else {
        int x = sx / k, y = sy / k;
        f1.push_back({x, y, 0});
    }

    if((tp2 & 1) == 0) {
        int x = tx / k, y = ty / k;
        f2.push_back({x + 1, y, k - tx % k});
        f2.push_back({x - 1, y, tx % k + 1});
        f2.push_back({x, y + 1, k - ty % k});
        f2.push_back({x, y - 1, ty % k + 1});
    }
    else {
        int x = tx / k, y = ty / k;
        f2.push_back({x, y, 0});
    }

    int ans = 1e18;

    if(((tp1 & 1) == 0 && (tp2 & 1) == 0)) {
        ans = min(ans, abs(sx - tx) + abs(sy - ty));
    }

    auto cal = [&](int x1, int y1, int x2, int y2) {
        int dis1 = 2 * max(abs(y1 - y2), abs(x1 - x2));
        int ma = max(abs(x1 - x2), abs(y1 - y2));
        int mi = min(abs(x1 - x2), abs(y1 - y2));
        int dis2 = mi * 2 + (ma - mi) / 2 * (k + 1);
        return min(dis1, dis2);
    };

    for(auto [x1, y1, v1] : f1) {
        for(auto [x2, y2, v2] : f2) {

            ans = min(ans, v1 + v2 + cal(x1, y1, x2, y2));
        }
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