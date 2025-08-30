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
#define MOD 1000000007

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll upper = 1000000;

    vector<int> dp(upper+1);
    dp[0] = 1;
    dp[1] = 2;

    vector<int> sum(upper+1);
    sum[0] = 1;
    sum[1] = 3;

    for(ll i = 2 ; i<=upper ; i++)
    {
        dp[i] = (dp[i-1] + sum[i-1] + (MOD + dp[i-1] - sum[i-2])*3) % MOD;
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }

    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    return 0;
}