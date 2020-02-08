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
struct s
{
    int pos;
    int nd;
    int idx;
};
int b[maxn];
int ans[maxn];
void update(int x){
    while(x < maxn){
        b[x]++;
        x += x & (-x);
    }
}
int query(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int>v(n);
    for(auto &i:v){
        cin >> i;
    }
    vector<s>vv;
    for(int i = 1 ; i <= q ; i++){
        int l, r, k;
        cin >> l >> r >> k;
        vv.pb({l-1,k,-i});
        vv.pb({r,k,i});
    }
    sort(vv.begin(),vv.end(),[](s x, s y){
        return x.pos < y.pos;
    });
    int ptr = 0;
    while(vv[ptr].pos == 0)ptr++;
    for(int i = 1 ; i <= n ; i++){
        update(v[i - 1]);
        while(ptr < 2 * q && vv[ptr].pos == i){
            if(vv[ptr].idx < 0){
                ans[abs(vv[ptr].idx)] -= query(vv[ptr].nd);
            }
            else{
                ans[abs(vv[ptr].idx)] += query(vv[ptr].nd);
            }
            ptr++;
        }
    }
    f1(q){
        cout << ans[i] << '\n';
    }
}
