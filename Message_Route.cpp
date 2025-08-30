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

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for(ll next : adj[curr])
        {
            if(dist[next] <= dist[curr]+1) continue;
            dist[next] = dist[curr]+1;
            q.push(next);
        }
    }

    if(dist[n-1] == INT_MAX)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    ll curr = n-1;
    vector<int> res;
    res.pb(curr);
    while(curr!=0)
    {
        for(ll next : adj[curr])
        {
            if(dist[next] != dist[curr]-1) continue;
            res.pb(next);
            curr = next;
            break;
        }
    }

    cout << res.size() << "\n";

    reverse(all(res));
    for(ll num : res) cout << num + 1 << " ";
    cout <<  "\n";
    
    return 0;
}