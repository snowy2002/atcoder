#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

struct Trie {
    int tot = 1;
    int ch[maxn][26], f[maxn];
    void insert(string s) {
        int len = s.length(), u = 1;
        for(int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if(!ch[u][c]) {
                ch[u][c] = ++tot;
            }
            u = ch[u][c];
            f[u] += 1;
        }
    }
}tr;

void solve() {
    int n = read();
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tr.insert(a[i]);
    }
    int ans = 0;
    for(int i = 2; i <= tr.tot; i++) {
        ans += tr.f[i] * (tr.f[i] - 1) / 2;
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