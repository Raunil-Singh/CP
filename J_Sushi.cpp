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
#define vi vector<int>
#define vvi vector<vector<int>>

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(20);

    ll n;
    cin >> n;
    vi v(n); inp(v);

    vi a(3,0); for(ll i : v) a[i-1]++;

    vector<vector<vector<long double>>> dp(n+1, vector<vector<long double>>(n+1, vector<long double>(n+1)));
    dp[0][0][0] = 0.0;

    for(ll k = 0 ; k<=n ; k++)
    for(ll j = 0 ; j<=n ; j++)
    for(ll i = 0 ; i<=n ; i++)
    {
        if(i+j+k > n) break;
        if(!i && !j && !k) continue;
        dp[i][j][k] = n;
        if(i) dp[i][j][k] += i*dp[i-1][j][k];
        if(j) dp[i][j][k] += j*dp[i+1][j-1][k];
        if(k) dp[i][j][k] += k*dp[i][j+1][k-1];
        dp[i][j][k] /= (i+j+k);
    }

    cout << dp[a[0]][a[1]][a[2]] << "\n";

    return 0;
}
        
    
