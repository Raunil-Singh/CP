// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

class Solution
{
private :

    vector<vector<int>> adj;
    vector<int> dist;
    ll ans;

    int dfs(ll prev, ll curr, ll valid, bool state) // state = true -> incoming are usable
    {
        ll temp = 0;
        if(dist[curr] == 3) state = !state;
        for(ll next : adj[curr])
        {
            if(next == prev) continue;
            temp += dfs(curr, next, valid, state);
        }
        if(dist[curr] == 3)
        {
            if(state) ans += temp;
            else ans += valid - (temp+1);
        }
        return temp + (dist[curr] >= 3);
    }

public :
    void solve(ll tc_no)
    {
        
        ll n;
        cin >> n;
        adj.assign(n, vector<int>());
        dist.assign(n, INT_MAX);

        for(ll i = 1 ; i<n ; i++)
        {
            ll a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        queue<int> q;
        for(ll i = 0 ; i<n ; i++)
        {
            if(adj[i].size() > 1) continue;
            q.push(i);
            dist[i] = 1;
        }

        ll dist_1 = q.size(), dist_2 = 0;
        ll seed = -1;

        while(!q.empty())
        {
            ll curr = q.front(); q.pop();
            for(ll next : adj[curr])
            {
                if(dist[next] <= dist[curr]+1) continue;
                dist[next] = dist[curr]+1;
                if(dist[next] == 2)
                {
                    dist_2++;
                    seed = next;
                }
                q.push(next);
            }
        }
        
        ans = dist_1 * (n-dist_1);
        if(seed!=-1) dfs(-1, seed, n-(dist_1+dist_2), true);

        cout << ans << "\n";

    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(i);
    }
    return 0;
}