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

vector<int> primes;

class Solution
{
private :

    vector<vector<int>> adj;
    int n;
    vector<int> a;
    int ans;

    void dfs(int curr, int prev, int g)
    {
        for(int num : primes)
            if(g%num)
            {
                ans += num;
                break;
            }

        for(int next : adj[curr])
        {
            if(next == prev) continue;
            dfs(next, curr, gcd(g, a[next-1]));
        }
    }

public :
    void solve(ll tc_no)
    {
        cin >> n;
        a.resize(n); inp(a);
        adj.resize(n+1);
        for(int i = 1 ; i<n ; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for(int i = 1 ; i<=n ; i++)
        {
            ans = 0;
            dfs(i, -1, a[i-1]);
            cout << ans << " ";
        }
        cout << "\n";
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

    primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173};

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(i);
    }
    return 0;
}