#include <bits/stdc++.h>
using namespace std;

long long next(long long x, int D) {
    int digits[D];
    long long A = 0, B = 0;

    for (int i = 0; i < D; i++) {
        digits[i] = x % 10;
        x /= 10;
    }
    sort(digits, digits + D);

    // #
    for (int i = D - 1; i >= 0; i--) {
        A *= 10;
        A += digits[i];
    } 
    
    // b
    for (int i = 0; i < D; i++) {
        B *= 10;
        B += digits[i];
    }

    return A - B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T; while (T --) {
        long long D, N, ans;
        cin >> D >> N;
        
        map<long long, int> stamp;
        int time_cnt = 0;
        stamp[N] = time_cnt++;

        while (1) {
            N = next(N, D);
            if (stamp.count(N)) {
                ans = time_cnt - stamp[N];
                break;
            } else {
                stamp[N] = time_cnt++;
            }
        }

        cout << ans << '\n';
    }
}
