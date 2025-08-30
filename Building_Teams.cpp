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

    ll n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());

    for(ll i = 0 ; i<m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> color(n, 0);

    for(ll i = 0 ; i<n ; i++)
    {
        if(color[i]) continue;
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while(!q.empty())
        {
            ll curr = q.front();
            q.pop();
            for(ll next : adj[curr])
            {
                if(color[next])
                {
                    if(color[next]!=color[curr]) continue;
                    else
                    {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
                color[next] = 1 + (color[curr]==1);
                q.push(next);
            }
        }
    }

    for(ll num : color) cout << num << " ";
    cout << "\n";
    
    return 0;
}