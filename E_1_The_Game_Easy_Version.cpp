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

    vector<int> w;
    vector<int> sorted_w;
    vector<vector<int>> adj;
    int n;
    int ans = 0;

    vector<int> solver(int prev, int curr)
    {
        auto merger = [](vector<int>v1, vector<int>v2) -> vector<int> {
            vector<int> res(v1.size() + v2.size());
            int a = 0, b = 0;
            int c = 0;
            while(a<v1.size() || b<v2.size())
            {
                if(b>=v2.size() || (a<v1.size() && v1[a] <= v2[b]))
                {
                    res[c] = v1[a];
                    a++;
                }
                else {
                    res[c] = v2[b];
                    b++;
                }
                c++;
            }
            return res;
        };

        vector<int> temp = {w[curr]};
        for(int next : adj[curr])
        {
            if(next==prev) continue;
            temp = merger(solver(curr, next), temp);
            if(ans!=0) return {};
        }

        // for(ll num : temp) cout << num << " ";
        // cout << "# " << curr+1 << " # ";

        int t1 = (sorted_w.end() - upper_bound(all(sorted_w), w[curr])) - (temp.end() - upper_bound(all(temp), w[curr]));
        if(t1 != 0) ans = curr+1;
        // cout << ans << " #\n";
        return temp;
    }

public :
    void solve(ll tc_no)
    {
        cin >> n;
        w.resize(n); inp(w);
        adj.resize(n);
        for(int i = 1 ; i<n ; i++)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        sorted_w = w;
        sort(all(sorted_w));

        solver(-1, 0);

        cout << ans << "\n";

    }
};

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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