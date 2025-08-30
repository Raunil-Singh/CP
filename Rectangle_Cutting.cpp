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

    ll a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a, vector<int>(b));

    for(ll i = 0 ; i<a ; i++) dp[i][0] = i;
    for(ll i = 0 ; i<b ; i++) dp[0][i] = i;

    for(ll i = 1 ; i<a ; i++)
    {
        ll m = i+1;
        for(ll j = 1 ; j<b ; j++)
        {
            ll n = j+1;
            if(i==j)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT_MAX;
            for(ll x = 1 ; x<=m-x ; x++)
            {
                dp[i][j] = min(dp[x-1][j] + dp[m-x-1][j] + 1, dp[i][j]);
            }
            for(ll x = 1 ; x<=n-x ; x++)
            {
                dp[i][j] = min(dp[i][x-1] + dp[i][n-x-1] + 1, dp[i][j]);
            }
        }
    }

    // for(ll i = 0 ; i<a ; i++)
    // {
    //     for(ll j = 0 ; j<b ; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << " # \n";
    // }

    cout << dp[a-1][b-1] << "\n";
    
    return 0;
}