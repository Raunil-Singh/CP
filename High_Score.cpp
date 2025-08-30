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

    ll n,m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for(vector<int> &edge : edges)
    {
        inp(edge);
        edge[2] *= -1;
        edge[0]--;
        edge[1]--;
    }

    vector<int> dist(n, 1e18);
    dist[0] = 0;

    for(ll i = 0 ; i<n+1 ; i++)
    {
        // cout << i << "# ";
        set<int> s;
        for(vector<int> edge : edges)
        {
            if(dist[edge[1]] > dist[edge[0]] + edge[2])
            {
                s.insert(edge[1]);
                dist[edge[1]] = dist[edge[0]] + edge[2];
            }
        }
        // for(ll num : dist) cout << num << " ";
        // cout << "\n";
        if(s.empty()) break;
        if(i == n-1 && s.find(n-1)!=s.end())
        {
            cout << "-1\n";
            return 0;
        }
        else if(i == n-1) break;
    }

    cout << (-dist[n-1]) << "\n";

    return 0;
}