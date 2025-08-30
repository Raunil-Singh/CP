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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n, vector<int>(n, 1e18));

    for(ll i = 0 ; i<m ; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }

    for(ll i = 0 ; i<n ; i++) adj[i][i] = 0;

    for(ll k = 0 ; k<n ; k++)
        for(ll i = 0 ; i<n ; i++)
            for(ll j = 0 ; j<n ; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    for(ll i = 0 ; i<q ; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << (adj[a][b]==1e18 ? -1 : adj[a][b]) << "\n";
    }

    return 0;
}