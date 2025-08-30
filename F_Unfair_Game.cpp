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

const long double eps = 1e-12;

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll cap = 200;

    vector<vector<vector<int>>> dp(cap+1, vector<vector<int>>(cap+1, vector<int>(cap+1)));

    for(ll i = 0 ; i<=cap ; i++)
    {
        for(ll j = 0 ; j<=cap ; j++)
        {
            for(ll k = 0 ; k<=cap ; k++)
            {
                dp[i][j][k] = ((i+j+k) ? ((i+k)%2 == 0 && (j+k)%2 == 0) : 0);
                ll comp = 0;
                if(i>0) comp = max(dp[i-1][j][k], comp); 
                if(j>0) comp = max(dp[i][j-1][k], comp);
                if(k>0) comp = max(dp[i][j][k-1], comp);
                dp[i][j][k] += comp;
            }
        }
    }

    ll t;
    cin >> t;

    while(t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d ;
        cout << dp[a][b][c] + d/2 << "\n";
    }
    
    return 0;
}