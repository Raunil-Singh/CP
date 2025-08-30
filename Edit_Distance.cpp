// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;

    ll n1 = s1.length(), n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1));
    dp[0][0] = 0;

    for(ll i = 1 ; i<=n1 ; i++) dp[i][0] = i;
    for(ll i = 1 ; i<=n2 ; i++) dp[0][i] = i;

    for(ll i = 1 ; i<=n1 ; i++)
    {
        for(ll j = 1 ; j<=n2 ; j++)
        {
            dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            if(s1[i-1] == s2[j-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            // cout << dp[i][j] << " ";
        }
        // cout << " # \n";
    }

    cout << dp[n1][n2] << "\n";
    
    return 0;
}