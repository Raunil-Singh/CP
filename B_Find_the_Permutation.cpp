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

    // Private functions and data members
    ll n;
    vector<string> adj;
    void arrange(vector<int> &v, int l, int r)
    {
        if(r-l<=0) return;
        ll i = l;
        for(ll j = l+1 ; j<=r ; j++)
        {
            if(v[l] == v[j]) continue;
            if(v[l] > v[j])
            {
                if(adj[v[l]][v[j]] == '1')
                {
                    i++;
                    swap(v[i], v[j]);
                }
            }
            else if(v[l] < v[j])
            {
                if(adj[v[l]][v[j]] == '0')
                {
                    i++;
                    swap(v[i], v[j]);
                }
            }
        }
        swap(v[l], v[i]);
        arrange(v, l, i-1);
        arrange(v, i+1, r);
    }

public :
    void solve(ll tc_no)
    {
        
        ll n;
        cin >> n;
        adj.resize(n);
        inp(adj);

        vector<int> v(n);
        for(ll i = 0 ; i<n ; i++) v[i] = i;

        arrange(v, 0, n-1);

        for(ll num : v) cout << num+1 << " ";
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(i);
    }
    return 0;
}