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
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    
    vector<int> v(n); inp(v);

    vector<vector<pair<int, int>>> dp(3, vector<pair<int, int>>(n, make_pair(-1, -1)));
    for(ll i = 0 ; i<n ; i++) dp[0][i] = make_pair(v[i], i);

    ll ans = -1;
    for(ll i = 1 ; i<n ; i++)
    {
        for(ll j = min(i, 2ll) ; j>=0 ; j--)
        {
            if(dp[j][i].S == -1)
            {
                dp[j][i].F = (dp[j-1][i-1].F + dp[0][i].F) - ((dp[0][i].S - dp[j-1][i-1].S));
                dp[j][i].S = i;
            }
            if(dp[j][i-1].F-dp[j][i].S > dp[j][i].F-dp[j][i-1].S) dp[j][i] = dp[j][i-1];
        }
        ans = max(ans, dp[2][i].F);
    }

    // for(ll j = 0 ; j<3 ; j++)
    // {
    //     for(auto x : dp[j]) cout << "(" << x.F << ", " << x.S << ")\t";
    //     cout << "\n";
    // }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}