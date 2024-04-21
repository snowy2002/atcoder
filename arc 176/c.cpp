#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

const int mod = 998244353;

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
}tr;

void solve() {
    int n = read(), m = read(), ok = 1;
    tr.init(n);
    for(int i = 1; i <= n; i++) tr.add(i, 1);
    vector<vector<pair<int, int>>> g(n + 1);
    vector G = g;
    vector<int> a(n + 1);
    for(int i = 1; i <= m; i++) {
        int aa = read(), bb = read(), cc = read();
        g[aa].push_back({bb, cc});
        g[bb].push_back({aa, cc});
    }
    for(int i = 1; i <= n; i++) {
        map<int, int> mp;
        int vv = 0;
        for(auto [v, val] : g[i]) {
            mp[val] += 1;
        }
        int cnt = 0;
        for(auto [key, val] : mp) {
            if(val >= 2) cnt += 1, vv = key;
        }
        if(cnt > 1) {
            cout << 0 << "\n";
            return;
        }
        if(cnt == 0) continue;
        a[i] = vv;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(a[i]) q.push(i);
    }
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto [v, val] : g[u]) {
            if(val == a[u]) continue;
            if(a[v]) continue;
            a[v] = val;
            q.push(v);
        }
    }
    int inf = 1e18;
    vector<int> f(n + 1), V(n + 1, inf), sz(n + 1, 1ll);
    vector<vector<int>> col(n + 1);
    iota(f.begin() + 1, f.end(), 1ll);
    set<int> s;
    auto fi = [&](auto fi, int x) -> int {
        if(f[x] != x) f[x] = fi(fi, f[x]);
        return f[x];
    };
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
        if(!a[i]) continue;
        if(s.find(a[i]) == s.end()) {
            cout << 0 << "\n";
            return;
        }
        s.erase(a[i]);
        tr.add(a[i], -1);
    }
    // return;
    for(int i = 1; i <= n; i++) {
        if(!a[i]) {
            for(auto [v, val] : g[i]) {
                if(a[v]) continue;
                if(i > v) continue;
                int fa = fi(fi, i);
                int fb = fi(fi, v);
                // cout << fa << " " << fb << "\n";
                if(fa == fb) {
                    cout << 0 << "\n";
                    return;
                }
                if(col[fa].size() < col[fb].size()) swap(fa, fb);
                for(auto val : col[fb]) {
                    col[fa].push_back(val);
                } 
                col[fa].push_back(val);
                V[fa] = min({V[fa], V[fb], val});
                sz[fa] = sz[fa] + sz[fb];
                f[fb] = fa;
            }
            continue;
        }
        for(auto [v, val] : g[i]) {
            if(val != max(a[i], a[v])) {
                cout << 0 << "\n";
                return;
            }
        }
    }
    cout << "ok\n";
    vector<tuple<int, int, int>> b;
    vector<vector<int>> co(n + 1);
    for(int i = 1; i <= n; i++) {
        // co[fi(fi, i)].push_back()
        if(a[i]) continue;
        if(fi(fi, i) == i) {
            b.push_back({V[i], sz[i], i});
            cout << i << " " << sz[i] << " " << V[i] << endl;
        }
    }
    cout << "!!!\n";
    sort(b.begin(), b.end());
    int ans = 1, now = 0;
    for(auto [val, sz, id] : b) {
        cout << val << "!!!\n"; 
        val = min(val, n + 1);
        int sum = tr.query(val - 1) - now; now += 1;
        // int sum;
        cout << sum << "!?\n";
        if(sum <= 0) {
            cout << 0 << "\n";
            return;
        }
        if(sz == 1) ans = ans * sum % mod;
        else ans = ans  % mod * sum % mod;
        for(int i : col[id]) {
            // cout << i << "->";
            tr.add(i, -1);
        }
    }
    cout << ans << "\n";
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