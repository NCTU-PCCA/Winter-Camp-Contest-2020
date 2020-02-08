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
vector<int>g[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    while(cin >> n >> k){
        int cont[n+5] = {};
        f1(n+1){
            g[i].clear();
        }
        f1(n){
            cin >> cont[i];
            int nxt = min(i + cont[i],n + 1);
            g[nxt].pb(i);
        }
        int ans = 0;
        queue<pair<int,int> >q;
        q.push({n+1,k});
        while(!q.empty()){
            int now = q.front().F;
            int left = q.front().S;
            q.pop();
            if(!left)break;
            for(auto i:g[now]){
                ans++;
                q.push({i,left-1});
            }
        }
        cout << ans << endl;
    }
}
