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

    map<vector<int>, int> m;
    ll ans;

    void solver(vector<int> v)
    {
        if(m.find(v)!=m.end()) return;
        
        // cout << v.size() << " # ";
        // for(ll num : v) cout << num << " ";
        // cout << "\n";
        
        m[v] = accumulate(all(v), 0LL);
        ans = max(m[v], ans);
        
        // bool flag = true; for(int i = 0 ; i<v.size() && flag ; i++) if(v[i] < 0) flag = false;
        // if(flag) return;
        
        if(v.size() == 1) return;
        
        vector<int> v1(v.size()-1);
        for(int i = 1 ; i<v.size() ; i++)
            v1[i-1] = v[i]-v[i-1];
        solver(v1);
        
        reverse(all(v));
        for(int i = 1 ; i<v.size() ; i++)
            v1[i-1] = v[i]-v[i-1];
        solver(v1);
    }

public :
    void solve(ll tc_no)
    {
        
        int n;
        cin >> n;
        vector<int> v(n); inp(v);

        ans = accumulate(all(v), 0LL);

        solver(v);

        cout << ans << "\n";
        
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