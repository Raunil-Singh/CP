#include <bits/stdc++.h>
using namespace std;

#define int long long

int bubble(vector<int> v, int n) {
    int cnt = 0;
    for(int i = n-1 ; i>=0 ; i--) {
        if(v[i] == i+1) continue;
        for(int j = 0 ; j<i ; j++) {
            if(v[j] > v[j+1]) {
                cnt++;
                swap(v[j], v[j+1]);
            }
        }
    }
    return cnt;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &num : v) cin >> num;

    int cnt = bubble(v, n);

    double ans = 0;
    if(cnt & 1) {
        ans++;
        cnt--;
    }

    ans += 2*cnt;

    cout << fixed << setprecision(6) << ans << "\n";

    // cout << cnt << "\n";

    return 0;
}