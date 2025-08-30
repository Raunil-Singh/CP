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

void dfs1(int prev, int curr, vector<int> &nc, vector<int> &dist, vector<vector<int>> &adj)
{
    // cout << "Entered " << curr << " $\n";
    for(int next : adj[curr])
    {
        if(next == prev) continue;
        dfs1(curr, next, nc, dist, adj);
        nc[curr] += nc[next];
        dist[curr] += dist[next] + nc[next];
    }
    // cout << curr << " " << dist[curr] << " " << nc[curr] << " #\n";
}

void dfs2(int prev, int curr, vector<int> &nc, int n, vector<int> &dist, vector<vector<int>> &adj)
{
    for(int next : adj[curr])
    {
        if(next == prev) continue;
        dist[next] += dist[curr] + n - (dist[next] + 2*nc[next]);
        dfs2(curr, next, nc, n, dist, adj);
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

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 1 ; i<n ; i++)
    {
        int x, y; cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    vector<int> nc(n, 1);
    vector<int> dist(n, 0);

    dfs1(-1, 0, nc, dist, adj);
    dfs2(-1, 0, nc, n, dist, adj);

    for(int num : dist) cout << num << " ";


    return 0;
}