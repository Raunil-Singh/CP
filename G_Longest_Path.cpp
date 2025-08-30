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

int solve(int curr, vector<int> &pathlen, vector<vector<int>> &adj)
{
    if(pathlen[curr]!=-1) return pathlen[curr];
    ll longest = -1;
    for(ll next : adj[curr])
        longest = max(longest, solve(next, pathlen, adj));
    return pathlen[curr] = longest+1;
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

    ll n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());
    for(ll i = 0 ; i<m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
    }

    vector<int> pathlen(n, -1);

    ll ans = 0;
    for(ll i = 0 ; i<n ; i++)
        ans = max(ans, solve(i, pathlen, adj));
    
    cout << ans << "\n";

    return 0;
}