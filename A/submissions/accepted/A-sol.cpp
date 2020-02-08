#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define x first
#define y second

int n;
vector<pll> p, ch;
ll ansr[200010], ansl[200010];

ll cross(pll a, pll b, pll o) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void build(ll ans[]) {
    ch.clear();
    for(int i = 0; i < n; i++) {
        ans[i] = p[i].y;
        int sz;
        while(sz = ch.size(), sz > 1 && cross(ch[sz - 1], p[i], ch[sz - 2]) > 0) {
            ch.pop_back();
            ans[i] = max(ans[i], ch.back().y);
        }
        ch.push_back(p[i]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll _x, _y;
        cin >> _x >> _y;
        p.push_back({_x, _y});
    }
    build(ansr);
    reverse(p.begin(), p.end());
    for(pll &i : p) {
        i.x = -i.x;
    }
    build(ansl);
    for(int i = 0; i < n; i++) {
        if(i) cout << ' ';
        cout << max(ansr[i], ansl[n - 1 - i]);
    }
    cout << '\n';
    return 0;
}
