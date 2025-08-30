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

void solve(ll tc_no)
{
    
    string s[2];
    string res;
    cin >> s[0] >> s[1] >> res;

    vector<vector<int>> dp(s[0].size()+1, vector<int>(s[1].size()+1, INT_MAX));
    dp[s[0].size()][s[1].size()] = 0;

    for(ll i = s[0].length()-1 ; i>=0 ; i--)
        dp[i][s[1].length()] = dp[i+1][s[1].length()] + (s[0][i] != res[res.length()-s[0].length()+i]);
    
    for(ll i = s[1].length()-1 ; i>=0 ; i--)
        dp[s[0].length()][i] = dp[s[0].length()][i+1] + (s[1][i] != res[res.length()-s[1].length()+i]);

    for(ll i = res.size()-1 ; i>=0 ; i--)
    {
        for(ll j = min((int)s[0].length()-1, i) ; i-j < s[1].length() && j>=0 ; j--)
            dp[j][i-j] = min(dp[j+1][i-j] + (s[0][j] != res[i]), dp[j][i-j+1] + (s[1][i-j] != res[i]));
    }

    // for(ll i = 0 ; i<=s[0].length() ; i++)
    // {
    //     for(ll j = 0 ; j<=s[1].length() ; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    cout << dp[0][0] << "\n";

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}