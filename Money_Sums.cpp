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

    ll n;
    cin >> n;
    vector<int> v(n); inp(n, v);

    int sum = accumulate(v.begin(), v.end(), 0);
    vector<bool> dp(sum+1, false);
    dp[0] = true;

    sum = 0;
    for(ll num : v)
    {
        sum += num;
        for(ll i = sum ; i>=num ; i--)
        dp[i] = (dp[i] || dp[i-num]);
    }
    
    ll count = 0;
    for(ll i = 1 ; i<=sum ; i++)
        count += dp[i];

    cout << count << "\n";
    for(ll i = 1 ; i<=sum ; i++)
        if(dp[i]) cout << i << " ";
    
    cout << "\n";

    return 0;
}