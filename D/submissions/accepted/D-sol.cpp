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
const int mod = 998244353;
ll dp[100005][205];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    while(cin >> n >> k){
        f1(k){
            dp[1][i] = 1;
        }
        fr(i,2,n+1){
            ll cur = 0;
            fr(j,1,k+1){
                cur += dp[i-1][j];
                cur %= mod;
                dp[i][j] = cur;
            }
        }
        ll ans = 0;
        f1(n-2){
            int left = n-1-i;
            ll pre = 0,suf = 0;
            fr(j,1,k){
                pre += dp[i][j];
                pre %= mod;
                suf += dp[left][j];
                suf %= mod;
                ans += pre * suf % mod;
                ans %= mod;
            }
        }
        cout << ans << endl;
    }
}