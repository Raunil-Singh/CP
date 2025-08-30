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

int solver(vector<int>&v)
{
    int n = v.size();
    if(n == 1) return v[0];
    if(n == 2) return abs(v[1]-v[0]);
    
    int ml = 0;
    for(int i = 0 ; i<n ; i++) ml = max(ml, v[i]);

    if(v.front() == ml || v.back() == ml) return ml;
    if(n == 3) return abs(v[1]-v[2]-v[0]);

    int ans = max(v[0], v[n-1]);
    for(int i = 2 ; i<n-2 ; i++) ans = max(ans, v[i]);

    if(v[1] == ml)
    {
        ans = max(ans, v[1]-v[0]);
        vector<int> temp;
        for(int i = 2 ; i<n; i++) temp.pb(v[i]);
        ans = max(ans, v[0]-v[1]+solver(temp));
    }
    if(v[n-2] == ml)
    {
        ans = max(ans, v[n-2]-v[n-1]);
        vector<int> temp;
        for(int i = 0 ; i<n-2; i++) temp.pb(v[i]);
        ans = max(ans, abs(v[n-1]-v[n-2]+solver(temp)));
    }
    return ans;

}

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<int> v(n); inp(v);

    cout << solver(v) << "\n";
    
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