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
#define MOD 998244353

void solve(ll tc_no)
{
    
    int n;
    cin >> n;
    vector<int> v(n-1); inp(v);

    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i<n-1 ; i++)
    {
        int pos = i+2;
        adj[v[i]].pb(pos);
    }

    vector<int> depth(n, 0);
    depth[0] = 1;
    vector<int> node(n+1, 0);
    node[1] = 1;
    queue<int> q;
    q.push(1);

    int d = 0;
    while(!q.empty())
    {
        int x = q.size();
        int sum = 0;
        while(x--)
        {
            int curr = q.front();
            q.pop();
            if(curr != 1)
            {
                node[curr] = depth[d-1];
                if(v[curr-2] != 1) node[curr] = (MOD + node[curr] - node[v[curr-2]]) % MOD;
                sum += node[curr];
                sum %= MOD;

                // cout << curr << " " << node[curr] << "#\n";
            }
            for(int next : adj[curr]) q.push(next);
        }
        if(d) depth[d] = sum;
        d++;
    }

    int ans = 0;
    for(int i = 0 ; i<=n ; i++)
    {
        ans = (ans + node[i]) % MOD;
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