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
        freopen("a.in", "r", stdin);
    #endif

    int n = read();
    vector a(n + 1, vector(n + 1, 'a'));
    vector b = a;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            cin >> b[i][j];
            if(a[i][j] != b[i][j]) {
                cout << i << " " << j << "\n";
            }
        }
}