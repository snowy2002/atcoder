#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

void solve() {
    int N = read(), n = read(), m = read(), d = read();
    N -= 1;
    int pos = read(), val = read();
    vector<int> a(N + 1), b(N + 1);
    vector<multiset<int>> S(n + 1);
    for(int i = 1; i <= N; i++) {
        a[i] = read(), b[i] = read();
        S[a[i]].insert(b[i]);
    }

    int inf = 1e18;
    vector f(n + 1, vector(n + 1, inf));
    vector g = f;
    for(int i = 0; i <= n; i++) {
        f[i][i] = 0;
        g[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        int aa = read(), bb = read(), cc = read();
        f[aa][bb] = f[bb][aa] = cc;
        g[aa][bb] = g[bb][aa] = 1;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || i == k || j == k) continue;
                if(f[i][j] > f[i][k] + f[k][j]) {
                    f[i][j] = f[i][k] + f[k][j];
                    g[i][j] = g[i][k] + g[k][j];
                }
                else if(f[i][j] == f[i][k] + f[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
                // f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
                // g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
            }
        }
    }

    // cout << f[4][5] << " " << f[4][7] << "!!!!\n";

    int day = 0;

    while(1) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += S[i].size();
        }
        if(cnt == 0) {
            cout << "WIN on day " << day << " with " << val << "!\n";
            break;
        }
        int ma = -1, pos1 = -1;
        for(int i = 0; i < n; i++) {
            auto it = S[i].upper_bound(val);
            if(it == S[i].begin()) continue;
            it --;
            if(*it > ma) {
                ma = *it;
                pos1 = i;
            }
            else if(*it == ma && f[pos][i] < f[pos][pos1]) {
                pos1 = i;
            }
            else if(*it == ma && f[pos][i] == f[pos][pos1] && g[pos][i] < g[pos][pos1]) {
                pos1 = i;
            }
        }
        if(ma == -1) {
            cout << "Lose on day " << day + 1 << " with " << val << ".\n";
            return;
        }
        int city1 = pos, city2 = pos1;
        if(city1 != city2) {
            day += f[pos][pos1];
            if(day > d) {
                cout << "Game over with " << val << ".\n";
                return;
            }
            pos = pos1;
            cout << "Move from " << city1 << " to " <<  city2 << ".\n";
        }
        S[pos1].erase(S[pos1].find(ma));
        
        day += 1;
        if(day > d) {
            cout << "Game over with " << val << ".\n";
            return;
        }
        cout << "Get " << ma << " at " << pos1 << " on day " << day << ".\n";
        val = val + ma;

        int res = 0, ok = 0;
        while(S[pos1].size()) {
            if(*S[pos1].begin() <= val) {
                ok = 1;
                res += *S[pos1].begin();
                S[pos1].erase(S[pos1].begin());
            } 
            else break;
        }
        if(res > val || S[pos1].size()) {
            if(ok) S[pos1].insert(res);
        }
        else {
            if(ok == 0) continue;
            day += 1;
            if(day > d) {
                cout << "Game over with " << val << ".\n";
                return;
            }
            cout << "Get " << res << " at " << pos1 << " on day " << day << ".\n";
            val += res;
        }
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