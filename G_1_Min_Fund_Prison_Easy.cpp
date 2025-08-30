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

void solve(ll tc_no)
{
    
    ll n, m, c;
    cin >> n >> m >> c;

    vector<int> deg(n, 0);
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0 ; i<m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }

    vector<int> val(n, 1);
    queue<int> q;

    for(int i = 0 ; i<n ; i++)
        if(deg[i] == 1) q.push(i);
    
    int ans = LLONG_MAX;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans = min(ans, val[curr]*val[curr] + (n-val[curr])*(n-val[curr]));
        // cout << ans << " # ";
        for(int next : adj[curr])
        {
            if(deg[next] == 0) continue;
            deg[next]--;
            val[next] += val[curr];
            if(deg[next] == 1)  q.push(next); 
        }
    }

    cout << ans << "\n";
    
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