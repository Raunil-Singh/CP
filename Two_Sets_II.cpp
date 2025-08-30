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

    ll n;
    cin >> n;

    if(n*(n+1)%4 != 0)
    {
        cout << "0\n";
        return 0;
    }

    vector<vector<int>> dp(n*(n+1)/4, vector<int>(n+1, 0));
    for(ll i = 2 ; i<=n && i<n*(n+1)/4 ; i++)
    {
        dp[i][i] = 1;
    }

    for(ll i = 0 ; i<n*(n+1)/4 ; i++)
    {
        for(ll j = n-1 ; j>1 ; j--)
        {
            if(i<=j) continue;
            dp[i][j] = (dp[i-j][j+1] + dp[i][j+1]) % MOD;
        }
    }

    cout << (dp.back())[2] << "\n";
    
    return 0;
}