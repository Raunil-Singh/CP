#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int inv(int a, int m = MOD) {
    return a <= 1 ? a : (m - (m/a) * inv(m%a) % m);
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &num : v) {
        cin >> num;
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++) {
        ans = add(1, ans);
        ans = mul(ans, inv(v[i]));
        ans = mul(ans, 100);
    }

    cout << ans << "\n";

    return 0;
}