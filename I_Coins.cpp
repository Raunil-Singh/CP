#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    cout << setprecision(20);
    int n;
    cin >> n;
    double p;
    vector<double> dp(n+1, 0.0);
    dp[0] = 1.0;
    for(int i = 1 ; i<=n ; i++) {
        cin >> p;
        for(int j = i ; j>=0 ; j--) {
            dp[j] = dp[j] * (1-p) + (j>0 ? dp[j-1] : 0.0) * p;
        }
    }

    double sum = 0.0;
    for(int i = n/2+1 ; i<=n ; i++) sum += dp[i];

    cout << sum << "\n";

    return 0;
}