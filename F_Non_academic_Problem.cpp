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

class Solution
{
private :

    int n, m, time;
    vector<vector<int>> adj;
    vector<int> tin;
    vector<int> lt;

    int dfs1(int prev, int curr, vector<int> &nodes, vector<int> &counts)
    {
        if(tin[curr]!=INT_MAX) return 0;
        tin[curr] = time;
        lt[curr] = time;
        time++;
        int count = 1;
        for(int next : adj[curr])
        {
            if(prev == next) continue;
            count += dfs1(curr, next, nodes, counts);
            lt[curr] = min(lt[next], lt[curr]);
            if(tin[curr] < lt[next]) nodes.pb(next);
        }
        return counts[curr] = count;
    }

    // int dfs2(int curr, vector<bool> &visited, vector<int> &counts)
    // {
    //     visited[curr] = true;
    //     int count = 1;
    //     for(int next : adj[curr])
    //     {
    //         if(visited[next]) continue;
    //         count += dfs2(next, visited, counts);
    //     }
    //     return counts[curr] = count;
    // }

public :
    void solve(ll tc_no)
    {
        
        cin >> n >> m;
        adj.assign(n, vector<int>());
        for(int i = 0 ; i<m ; i++)
        {
            ll a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        vector<int> counts(n, 0);
        vector<int> nodes;
        tin.assign(n, INT_MAX);
        lt.resize(n);
        time = 0;
        dfs1(-1, 0, nodes, counts);

        // for(int num : nodes) cout << num << " ";
        // cout << "#\n";
        // for(int num : counts) cout << num << " ";
        // cout << "#\n";
        
        int ans = 0;
        for(int num : nodes)
            ans = max(ans, counts[num] * (n-counts[num]));
        
        cout << n*(n-1)/2 - ans << "\n";

    }
};

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
    {
        Solution obj;
        obj.solve(i);
        // cout << "-----------------\n";
    }
    return 0;
}