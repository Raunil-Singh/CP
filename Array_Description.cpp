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

    ll n, m;
    cin >> n >> m;

    vector<int> v(n); inp(n, v);

    for(ll i = 1 ; i<n ; i++)
    {
        if(v[i] == 0 || v[i-1] == 0) continue;
        if(abs(v[i]-v[i-1]) > 1)
        {
            cout << "0\n";
            return 0;
        }
    }

    ll last = -1;
    ll res = 1;
    for(ll i = 0 ; i<=n ; i++)
    {
        if(i == n || v[i]!=0)
        {
            if(i-last > 1)
            {
                // cout << i << "\n";
                vector<vector<int>> dp(m, vector<int>(i-last, 0));
                if(last == -1)
                {
                    for(ll j = 0 ; j<m ; j++) dp[j][0] = 1;
                }
                else
                    for(ll j = max(0ll, v[last]-2) ; j<=min(m-1, v[last]) ; j++) dp[j][0] = 1;
                for(ll j = 1 ; j<i-last ; j++)
                    for(ll k = 0 ; k<m ; k++) dp[k][j] = (dp[k][j-1] + (k-1>=0 ? dp[k-1][j-1] : 0) + (k+1<m ? dp[k+1][j-1] : 0)) % MOD;
                
                // for(ll j = 0 ; j<m ; j++)
                // {
                //     for(ll k = 0 ; k<i-last ; k++)
                //         cout << dp[j][k] << " ";
                //     cout << " # \n";
                // }
                if(n != i)
                    res = (res * ((dp[v[i]-1].back()) % MOD)) % MOD;
                else
                {
                    ll sum = 0;
                    for(ll x = 0 ; x<m ; x++)
                        sum += dp[x][i-last-2];
                    res = (res*((sum) % MOD)) % MOD;
                }
            }
            last = i;
        }
        // cout << last << "**\n";
    }

    cout << res << "\n";
    
    return 0;
}