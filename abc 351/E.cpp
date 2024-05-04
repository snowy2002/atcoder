#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

void solve() {
    int n = read();
    vector<pair<int, int>> a, b;
    for(int i = 1; i <= n; i++) {
        int aa = read(), bb = read();
        if((aa + bb) & 1) {
            a.push_back({aa + bb, aa - bb});
        }
        else {
            b.push_back({aa + bb, aa - bb});
        }
    } 
    int ans = 0;
    auto cal = [&](vector<pair<int, int>> a) -> int {
        int n = a.size();
        vector<int> x(n + 1), sx(n + 1);
        vector<int> y(n + 1), sy(n + 1);
        for(int i = 0; i < n; i++) {
            x[i + 1] = a[i].first;
            y[i + 1] = a[i].second; 
        }
        sort(x.begin() + 1, x.end());
        sort(y.begin() + 1, y.end());
        for(int i = 1; i <= n; i++) {
            sx[i] = sx[i - 1] + x[i];
            sy[i] = sy[i - 1] + y[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += x[i] * i - sx[i];
            ans += y[i] * i - sy[i];
            ans += (sx[n] - sx[i]) - x[i] * (n - i);
            ans += (sy[n] - sy[i]) - y[i] * (n - i);
        }
        return ans;
    };
    ans += cal(a);
    ans += cal(b);
    cout << ans / 4 << "\n";
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