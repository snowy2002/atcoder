#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

signed main() {
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    #else
        // freopen("a.in", "r", stdin);
    #endif

    int n = read();
    int lt = -1, ans = 0;
    vector<int> a(n + 1);
    vector<int> stk;
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) {
        if(stk.size() == 0) {
            stk.push_back(a[i]);
        }
        else {
            int now = a[i];
            while(stk.size()) {
                int u = stk.back();
                if(u != now) {
                    break;
                }
                now += 1;
                stk.pop_back();
            }
            stk.push_back(now);
        }
    }
    cout << stk.size() << "\n";
}