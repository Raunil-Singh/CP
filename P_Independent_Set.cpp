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

#define MOD 1000000007

pair<int, int> solve(int prev, int curr, vector<vector<int>> &adj)
{
    pair<int, int> res = mpr(1, 1);
    for(ll next : adj[curr])
    {
        if(prev == next) continue;
        pair<ll, ll> p = solve(curr, next, adj);
        res.F = (res.F*p.F) % MOD;
        res.S = (res.S*p.S) % MOD;
    }
    swap(res.F, res.S);
    return mpr((res.F+res.S) % MOD, res.S);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n;
    cin >> n;
    
    vector<vector<int>> adj(n, vector<int>());
    vector<int> deg(n, 0);
    for(ll i = 1 ; i<n ; i++)
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


    /* In Free time find the reason why this iterative code is wrong */

    // vector<vector<int>> dp(n, vector<int>(2, 1));
    // queue<int> q;
    // for(ll i = 0 ; i<n ; i++)
    //     if(deg[i] <= 1)q.push(i);

    // ll ans = 0;
    // while(!q.empty())
    // {
    //     ll curr = q.front();
    //     q.pop();
    //     for(ll next : adj[curr])
    //     {
    //         deg[next]--;
    //         dp[curr][0] = (dp[curr][0]*dp[next][0]) % MOD;
    //         dp[curr][1] = (dp[curr][1]*dp[next][1]) % MOD;
    //         if(deg[next] == 1)
    //         {
    //             q.push(next);
    //         }
    //     }

    //     dp[curr][0] = (dp[curr][0] + dp[curr][1]) % MOD;
    //     dp[curr][1] = (dp[curr][0] - dp[curr][1] + MOD) % MOD;

    //     swap(dp[curr][0], dp[curr][1]);
    //     dp[curr][0] = (dp[curr][0]+dp[curr][1]) % MOD;
    // }
    // cout << ans << "\n";

    cout << solve(-1, 0, adj).F << "\n";
    
    return 0;
}