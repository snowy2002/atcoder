#include<bits/stdc++.h>
using namespace std;
#define time chrono::system_clock::now().time_since_epoch().count()
mt19937_64 rnd(time);
#define maxn 1000005
#define int long long

int read() {int x;cin>>x;return x;}

struct ST{
    #define Maxn 300005
    long long tr[Maxn<<2],a[Maxn<<2],mx[Maxn<<2],mi[Maxn<<2];
    void init() {
        for(int i=1;i<Maxn*4;i++) {
            tr[i]=a[i]=mx[i]=0;
            mi[i]=1e9;
        }
    }
    void pushup(int k) {
        mx[k]=max(mx[k<<1],mx[k<<1|1]);
        mi[k]=min(mi[k<<1],mi[k<<1|1]);
        tr[k]=tr[k<<1]+tr[k<<1|1];
    }
    void modify(int k,int l,int r,int x,int val) {
        if(l==r) {
            tr[k]=mi[k]=mx[k]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid) modify(k<<1,l,mid,x,val);
        else modify(k<<1|1,mid+1,r,x,val);
        pushup(k);
    }
    int query_sum(int k,int l,int r,int x,int y) {
        if(x<=l&&r<=y) return tr[k];
        int mid=(l+r)>>1,ans=0;
        if(x<=mid) ans+=query_sum(k<<1,l,mid,x,y);
        if(mid+1<=y) ans+=query_sum(k<<1|1,mid+1,r,x,y);
        return ans;
    }
    int query_mx(int k,int l,int r,int x,int y) {
        if(x<=l&&r<=y) return mx[k];
        int mid=(l+r)>>1,ans=0;
        if(x<=mid) ans=max(ans,query_mx(k<<1,l,mid,x,y));
        if(mid+1<=y) ans=max(ans,query_mx(k<<1|1,mid+1,r,x,y));
        return ans;
    }
    int query_min(int k,int l,int r,int x,int y) {
        if(x<=l&&r<=y) return mi[k];
        int mid=(l+r)>>1,ans=1e9;
        if(x<=mid) ans=min(ans,query_min(k<<1,l,mid,x,y));
        if(mid+1<=y) ans=min(ans,query_min(k<<1|1,mid+1,r,x,y));
        return ans;
    }
}st1,st2;

void solve() {
    int n = read(), c = read();
    int q = read();
    
    int inf = 1e13;
    st1.modify(1, 1, n, 1, c);
    st2.modify(1, 1, n, 1, c * n);
    for(int i = 2; i <= n; i++) {
        st1.modify(1, 1, n, i, -inf);
        st2.modify(1, 1, n, i, -inf);
    }

    for(int i = 1; i <= q; i++) {
        int x = read(), val = read();
        int res1 = st1.query_mx(1, 1, n, 1, x);
        int res2 = st2.query_mx(1, 1, n, x, n);
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
    return 0;
}