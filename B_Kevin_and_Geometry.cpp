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

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<int> v(n); inp(v);

    sort(all(v));

    ll curr = -1;
    for(ll i = 1 ; i<n ; i++)
        if(v[i] == v[i-1]) curr = v[i] + v[i-1];
    
    ll temp = curr;
    vector<int> res;
    for(ll num : v)
        if(num*2 == temp || temp == num)
            temp -= num;
        else res.pb(num);
    
    for(ll i = 1 ; i<res.size() ; i++)
    {
        if(res[i] - res[i-1] < curr)
        {
            cout << res[i] <<  " " << res[i-1] <<  " " << curr/2 <<  " " << curr/2 << "\n";
            return;
        }
    }
    cout << "-1\n";
    
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