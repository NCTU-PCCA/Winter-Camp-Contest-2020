#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
int mx[maxn<<2];
void pushup(int x){
    mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
void build(int x,int l,int r){
    if(l == r){
        cin >> mx[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1, l, mid);
    build(x<<1|1, mid + 1, r);
    pushup(x);
}
int query(int x, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r){
        return mx[x];
    }
    int mid = (l + r) >> 1;
    int ret = 0;
    if(ql <= mid){
        ret = max(ret,query(x<<1,l,mid,ql,qr));
    }
    if(qr > mid){
        ret = max(ret,query(x<<1|1,mid+1,r,ql,qr));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    build(1,1,n);
    multiset<ll>ans;
    set<int>u;
    u.insert(0);
    u.insert(n + 1);
    ans.insert((ll)n*mx[1]);
    while(m--){
        int d;
        cin >> d;
        int ub = *u.lower_bound(d);
        ub--;
        int lb = *(prev(u.lower_bound(d)));
        lb++;
        int sz = ub - lb + 1;
        int mx = query(1,1,n,lb,ub);
        ans.erase(ans.find((ll)sz * mx));
        int rlb = d + 1;
        int lub = d - 1;
        u.insert(d);
        if(lub >= lb){
            ans.insert((ll)(lub - lb + 1) * query(1,1,n,lb,lub));
        }
        if(ub >= rlb){
            ans.insert((ll)(ub - rlb + 1) * query(1,1,n,rlb,ub));
        }
        cout << *(ans.rbegin()) << '\n';
    }
}
