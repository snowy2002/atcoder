#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

void solve() {
    string s, t;
    cin >> s >> t;
    int ls = s.length(), lt = t.length();
    int now = 0;
    for(int i = 0; i < lt; i++) {
        if(t[i] == s[now]) {
            cout << i + 1 << " ";
            now += 1;
        }
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
}