#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

struct Fenwick_Tree {
    using ll = long long;
    int sz, M; 
    ll tr[maxn];
    void init(int n) {
        memset(tr, 0, sizeof(ll) * (n + 1));
        sz = n , M = __lg(sz) + 1;
    }
    void add(int i, ll x) {
        for (; i <= sz; i += i & -i) tr[i] += x;
    }
    ll query(int i) {
        ll res ; 
        for (res = 0 ; i; i -= i & -i) res += tr[i];
        return res;
    }
    int rk(ll k) {
        int pos = 0 ; 
        for (int i = M - 1; ~i; --i) 
            if (pos + (1 << i) <= sz && k > tr[pos + (1 << i)])
                pos += 1 << i , k -= tr[pos];
        return pos + 1;
    }
}tr1, tr2;

void solve() {
    int n = read();
    vector<pair<int, int>> a(n + 1);
    tr1.init(n);
    tr2.init(n);
    for(int i = 1; i <= n; i++) {
        a[i].first = read();
        a[i].second = i;
    }
    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i++) {
        int id = a[i].second;
        // cout << id << " " << a[i].first << "!!???\n";
        int val = tr2.query(id);
        int cnt = tr1.query(id);
        ans += a[i].first * (cnt) - val;
        tr2.add(id, a[i].first);
        tr1.add(id, 1);
        // cout << ans << "!!\n";
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