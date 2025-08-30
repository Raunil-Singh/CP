#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define MOD 1000000007LL
 
int inv(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    } 
    return x < 0 ? x + m : x;
} 
 
int add(int a, int b) {
    return (a + b + MOD) % MOD;
}
 
int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int del = mul(2, inv(mul(n, n-1)));
    int p = mul(m, del);
    int num = 0;
    for(int i = 0 ; i<m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        num += c;
    }
    // num = mul(num, inv(m));
    int ans = 0;
    for(int i = 1 ; i<=k ; i++) {
        ans = add(ans, mul(num, del));
        num = add(num, p);
    }
    cout << ans << "\n";
}
 
signed main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}