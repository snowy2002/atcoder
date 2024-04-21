#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

int cal(int x) {
    return x * (x + 1) / 2;
}

void solve() {
    int n = read(), m = read(), k = read();
    string s;
    cin >> s;
    s = " " + s;
    vector<int> sum0(n + n + 1), sum1(n + n + 1), sum(n + n + 1);
    for(int i = 1; i <= n; i++) {
        sum0[i] = sum0[i - 1] + (s[i] == '0');
        sum1[i] = sum1[i - 1] + (s[i] == '1');
        sum[i] = sum[i - 1] + i * (s[i] == '1');
    }
    for(int i = n + 1; i <= 2 * n; i++) {
        sum0[i] = sum0[i - 1];
        sum1[i] = sum1[i - 1];
        sum[i] = sum[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        int l = 0, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int L = max(1ll, i - mid);
            int R = min(n, i + mid);
            if(sum0[R] - sum0[L - 1] >= m) {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        int L = max(1ll, i - l);
        int R = min(n, i + l);
        // cout << "LR:" << L << " " << R << "\n";
        if(sum0[R] - sum0[L - 1] > m) {
            if(s[L] == '0') L += 1;
            else R -= 1;
        }
        int ans1 = cal(i - L);
        int ans2 = cal(R - i);
        if(R - L + 1 >= k) {
            int l = 0, r = n;
            while(l <= r) {
                int mid = (l + r) >> 1;
                int L = max(1ll, i - mid);
                int R = min(n, i + mid);
                if(R - L + 1 >= k) {
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            int L = max(1ll, i - l);
            int R = min(n, i + l);
            if(R - L + 1 > k) {
                if(L == 1) R -= 1;
                else L += 1;
            }
            // cout << L << " " << R << "!!!\n";
            int a1 = cal(i - L) + cal(R - i);
            // cout << ans1 + ans2 << "!!!\n";
            cout << a1 << " \n"[i == n];

            continue;
        }
        int need = k - (R - L + 1);
        // cout << "need:" << need << "\n";
        r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int LL = max(1ll, i - mid);
            int RR = min(n, i + mid);
            if(sum1[L - 1] - sum1[LL - 1] + sum1[RR] - sum1[R] >= need) {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        int LL = max(1ll, i - l);
        int RR = min(n, i + l);
        if(sum1[L - 1] - sum1[LL - 1] + sum1[RR] - sum1[R] > need) {
            if(s[LL] == '1') LL += 1;
            else RR -= 1;
        }
        int a1 = (sum1[L - 1] - sum1[LL - 1]) * i - (sum[L - 1] - sum[LL -  1]);
        int a2 = -(sum1[RR] - sum1[R]) * i + (sum[RR] - sum[R]);
        cout << a1 + a2 + ans1 + ans2 << " \n"[i == n];
    }
}

signed main() {
    #ifdef ONLINE_JUDGE
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    #else
        freopen("a.in", "r", stdin);
    #endif

    int t = read();
    while(t--) solve();
    return 0;
}