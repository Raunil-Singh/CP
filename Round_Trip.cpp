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

void dfs(vector<vector<int>> &adj, int prev, int curr, set<int> &seen,int &status, vector<int> &res)
{
    if(seen.find(curr)!=seen.end())
    {
        res.pb(curr);
        status = 1;
        return;
    }
    seen.insert(curr);
    for(ll next : adj[curr])
    {
        if(prev == next) continue;
        dfs(adj, curr, next, seen, status, res);
        if(status!=0) break;
    }
    if(status == 1)
    {
        res.pb(curr);
        if(curr == res[0]) status++;
        return;
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

    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>()); 
    for(ll i =0 ; i<m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    set<int> seen;
    vector<int> res;
    int status = 0;
    for(ll i = 0 ; i<n && status==0 ; i++)
    {
        if(seen.find(i)!=seen.end()) continue;
        dfs(adj, -1, i, seen, status, res);
    }

    if(res.size() == 0) cout << "IMPOSSIBLE\n";
    else
    {
        cout << res.size() << "\n";
        for(ll num : res) cout << num+1 << " ";
        cout << "\n";
    }

    return 0;
}