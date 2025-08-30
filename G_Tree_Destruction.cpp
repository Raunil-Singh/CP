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

class Solution
{
private :

    map<int, vector<int>> adj;
    vector<int> deg;

    int a1, a2;
    void insert_res(int val)
    {
        if(val >= a1)
        {
            a2 = a1;
            a1 = val;
        }
        else if(val >= a2) a2 = val;
    }

    ll compute(int par, int curr)
    {
        if(deg[curr] <= 1 && par!=-1)
        {
            insert_res(0);
            return 0;
        }

        int f = 0, s = 0;

        for(int next : adj[curr])
        {
            if(next == par) continue;
            ll val = compute(curr, next);
            if(val >= f)
            {
                s = f;
                f = val; 
            }
            else if(val > s) s = val;
        }

        insert_res(max(deg[curr], max(deg[curr] - 1 + f, deg[curr] - 2 + f + s)));

        return max(deg[curr] - 2 + f, deg[curr] - 1);
    }

public :
    void solve(ll tc_no)
    {
        a1 = 0;
        a2 = 0;

        ll n;
        cin >> n;

        if(n <= 1)
        {
            cout << "0\n";
            return;
        }

        deg.assign(n, 0);

        for(ll i = 1 ; i<n ; i++)
        {
            ll a, b; cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
            deg[a]++;
            deg[b]++;
        }

        compute(-1, 0);

        cout << a1 << "\n";
        
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(i);
    }
    return 0;
}