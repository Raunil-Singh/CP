// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]
#define all(x) x.begin(), x.end()

class Solution
{
private :

    map<int, vector<int>> adj;
    vector<int> par;
    vector<int> deg;

    void dfs1(int curr)
    {
        for(ll next : adj[curr])
        {
            if(next == par[curr]) continue;
            par[next] = curr;
            dfs1(next);
        }
    }

    int dfs2(int curr, int p, vector<int> &temp, bool flag)
    {
        if(curr == 0)
        {
            priority_queue<int> pq(all(temp));
            ll ans = 0;
            for(ll i = 0 ; i<p && !pq.empty() ; i++)
            {
                ans++;
                pq.pop();
            }
            while(!pq.empty())
            {
                ans += 2*pq.top()-1;
                pq.pop();
            }
            return ans;
        }
        if(flag) temp.pb(deg[curr]);
        return (flag ? 0 : 1) + dfs2(par[curr], p, temp, !flag);
    }

public :
    void solve(ll tc_no)
    {
        
        ll n, q;
        cin >> n >> q;
        deg.assign(n, 0);
        par.resize(n);

        for(ll i = 1 ; i<n ; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
            deg[a]++;
            deg[b]++;
        }

        par[0] = 0;
        dfs1(0);

        while(q--)
        {
            ll v, p;
            cin >> v >> p;
            v--;
            vector<int> temp;
            cout << dfs2(v, p, temp, false) % 998244353ll << "\n";
        }
        
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