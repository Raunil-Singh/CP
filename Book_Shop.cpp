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

    signed n, x;
    cin >> n >> x;

    vector<signed> h(n+1), s(n+1);
    for(ll i = 1 ; i<=n ; i++) cin >> h[i];
    for(ll j = 1 ; j<=n ; j++) cin >> s[j];

    vector<int> dp(x+1, 0);

    for(ll i = 1 ; i<=n ; i++)
    {
        for(ll j = x ; j>=h[i] ; j--)
        {
            dp[j] = max(dp[j-h[i]]+s[i], dp[j]);
        }
    }
        
    cout << dp[x] << "\n";
    
    return 0;
}