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

#define MOD 1000000007

void multiply(vector<vector<int>> &res, vector<vector<int>> &a, vector<vector<int>> &b, int n)
{
    for(ll i = 0 ; i<n ; i++)
    {
        for(ll j = 0 ; j<n ; j++)
        {
            ll ans = 0;
            for(ll k = 0 ; k<n ; k++)
                ans = (ans + (a[i][k]*b[k][j]) % MOD) % MOD;
            res[i][j] = ans;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n, vector<int>(n)); for(vector<int>&vec : adj) inp(vec);

    ll dim = 60;

    vector<vector<vector<int>>> dp(dim, vector<vector<int>>(n, vector<int>(n)));

    dp[0] = adj;

    for(ll i = 1 ; i<dim ; i++) multiply(dp[i], dp[i-1], dp[i-1], n);

    vector<vector<int>> res(n, vector<int>(n));
    for(ll i = 0 ; i<n ; i++) for(ll j = 0 ; j<n ; j++) res[i][j] = (i==j);

    for(ll i = 0 ; i<dim ; i++)
    {
        if(k&(1LL<<i))
        {
            vector<vector<int>> temp(n, vector<int>(n));
            multiply(temp, res, dp[i], n);
            res = temp;
        }
    }

    ll ans = 0;
    for(ll i = 0 ; i<n ; i++) for(ll j = 0 ; j<n ; j++) ans = (ans + res[i][j]) % MOD;

    cout << ans << "\n";

    return 0;
}