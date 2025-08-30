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
    vector<vector<int>> v(n, vector<int>(3)); for(vector<int> &x : v) inp(x);

    vector<vector<int>> dp(3, vector<int>(n, 0));
    dp[0][0] = v[0][0];
    dp[1][0] = v[0][1];
    dp[2][0] = v[0][2];
    
    for(ll i = 1 ; i<n ; i++)
        for(ll j = 0 ; j<3 ; j++)
            dp[j][i] = max(dp[(j+1)%3][i-1], dp[(j+2)%3][i-1]) + v[i][j];
        
    cout << max(dp[2][n-1], max(dp[1][n-1], dp[0][n-1])) << "\n";

    return 0;
}