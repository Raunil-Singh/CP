// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n;
    cin >> n;
    vector<int> v(n); inp(v);

    vector<vector<int>> dp(n, vector<int>(n));
    for(ll i = 0 ; i<n ; i++) dp[i][i] = 0;

    for(ll i = 1 ; i<n ; i++) v[i] += v[i-1];

    for(ll i = 2 ; i<=n ; i++) // Window Size!
    {
        for(ll j = 0 ; j<n && j+i-1<n ; j++)
        {
            ll cost = (j==0 ? v[i-1] : v[i+j-1]-v[j-1]);
            dp[j][j+i-1] = LLONG_MAX;
            for(ll temp = 1 ; temp<i ; temp++)
                dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][j+temp-1] + dp[j+temp][j+i-1]);
            dp[j][j+i-1] += cost;
        }
    }

    cout << dp[0][n-1] << "\n";
    
    return 0;
}