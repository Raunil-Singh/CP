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

    ll n; cin >> n;
    vector<ll> v(n); inp(n, v);

    vector<vector<int>> dp(n, vector<int>(n));
    for(ll i = 0 ; i<n ; i++) dp[i][i] = v[i];

    for(ll i = 1 ; i<n ; i++) v[i] += v[i-1];

    for(ll i = 1 ; i<n ; i++)
        for(ll j = i ; j<n ; j++)
            dp[j-i][j] = (v[j] - (i==j ? 0 : v[j-i-1])) - min(dp[j-i+1][j], dp[j-i][j-1]);

    // for(ll i = 0 ; i<n ; i++)
    // {
    //     for(ll j = 0 ; j<n;  j++)
    //         if(j<i) cout << "\t";
    //         else cout << dp[i][j] << "\t";
    //     cout << " # \n";
    // }

    cout << dp[0][n-1] << "\n";
    
    return 0;
}