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

    ll n, x;
    cin >> n >> x;

    vector<int> v(n); inp(n, v);

    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    for(ll i = 1 ; i<=x ; i++)
    {
        for(ll num : v)
        {
            if(i-num < 0) continue;
            dp[i] = min(dp[i], dp[i-num] + 1);
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << "\n";
    
    return 0;
}