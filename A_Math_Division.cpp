#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007LL

int inv(int a) {
    return a<=1 ? a : MOD - (int)(MOD/a) * inv(MOD%a) % MOD;
}

int add(int a, int b) {
    return (a + b + MOD) % MOD;
}

int mul(int a, int b) {
    return (a * b) % MOD;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mod2 = inv(2);
    int a = 0, b = 1;
    for(int i = 1 ; i<n ; i++) {
        int x, y;
        if(s[i] == '0') {
            x = add(a, 1);
            y = add(mul(a + b, mod2), 1); 
        }
        else {
            x = add(mul(a + b, mod2), 1);
            y = add(b, 1);
        }
        a = x;
        b = y; 
    }

    cout << a << "\n";
}

signed main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
 *
 *      1 0 0 1 0 1
 * 
 * 
 */