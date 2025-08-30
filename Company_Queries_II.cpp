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

void dfs(int curr, int val, vector<int> &lvl, vector<vector<int>>&adj)
{
    lvl[curr] = val;
    for(int next : adj[curr])
        dfs(next, val+1, lvl, adj);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> v(n, vector<int>(20, -2));
    vector<vector<int>> adj(n);
    for(int i = 1 ; i<n ; i++)
    {
        cin >> v[i][0];
        v[i][0]--;
        adj[v[i][0]].pb(i);
    }

    for(int i = 1 ; i<20 ; i++)
        for(int j = 0 ; j<n ; j++)
            if(v[j][i-1] != -2) v[j][i] = v[v[j][i-1]][i-1];
    
    vector<int> lvl(n);
    dfs(0, 0, lvl, adj);

    auto lca = [v, lvl](int a, int b) -> int {
        if(lvl[a] < lvl[b]) swap(a, b);
        int diff = lvl[a]-lvl[b];
        for(int i = 0 ; i<20 ; i++)
            if(diff & (1<<i)) a = v[a][i];
        if(a==b) return b;
        for(int i = 19 ; i>=0 ; i--)
        if(v[a][i] != -2 && v[a][i] != v[b][i])
        {
            a = v[a][i];
            b = v[b][i];
        }
        return v[a][0];
    };

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << lca(a, b)+1 << "\n";
    }
    
    return 0;
}