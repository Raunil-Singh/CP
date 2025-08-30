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

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void dfs1(int prev, int curr, int val, vector<int> &lvl, vector<vector<int>> &adj, vector<vector<int>> &v)
{
    v[curr][0] = prev;
    lvl[curr] = val;
    for(int next : adj[curr])
    {
        if(prev == next) continue;
        dfs1(curr, next, val+1, lvl, adj, v);
    }
}

void solve(ll tc_no)
{
    
    int n;
    cin >> n;
    vector<int> val(n); inp(val);

    vector<vector<int>> v(n, vector<int>(20, -2));
    vector<vector<int>> adj(n);
    for(int i = 1 ; i<n ; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> lvl(n);
    dfs1(-2, 0, 0, lvl, adj, v);
    for(int i = 1 ; i<20 ; i++)
        for(int j = 1 ; j<n ; j++)
            if(v[j][i-1]!=-1) v[j][i] = v[v[j][i-1]][i-1];

    vector<int> res(n);
    for(int i = 0 ; i<n ; i++)
    {
        int p = lvl[i] - 2*val[i] - 1;
        if()
    }

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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