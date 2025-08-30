#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int w, b;
    cin >> w >> b;
    vector<vector<vector<double>>> dp(w+1, vector<vector<double>>(b+1, vector<double>(2, 0.0)));

    // 0 => dragon, 1 => princess

    dp[0][0][0] = 1.0;

    for(int i = 1 ; i<=w ; i++) {
        dp[i][0][0] = 1.0;
        dp[i][0][1] = 1.0;
    }

    for(int j = 1 ; j<=b ; j++) {
        dp[0][j][0] = 1.0;
    }

    for(int i = 1 ; i<=w ; i++) {
        for(int j = 1 ; j<=b ; j++) {
            dp[i][j][0] = (1.0*i)/(i+j) + (1.0*j)/(i+j) * ((1.0*i)/(i+j-1)*(1 - dp[i-1][j-1][1]) + (1.0*(j-1))/(i+j-1)*(1.0 - dp[i][max(0LL, j-2)][1]));
            dp[i][j][1] = (1.0*i)/(i+j) + (1.0*j)/(i+j) * (1 - dp[i][j-1][0]);
        }
    }

    // for(int i = 0 ; i<=w ; i++) {
    //     for(int j = 0 ; j<=b ; j++) {
    //         cout << dp[i][j][1] << ' ';
    //     }
    //     cout << "\n";
    // }

    cout << fixed << setprecision(15);
    cout << dp[w][b][1] << "\n";

    return 0;
}