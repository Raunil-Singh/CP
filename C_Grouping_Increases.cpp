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

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<int> v(n); inp(v);

    ll cost = 0;
    ll x[] = {0,0};
    for(ll i = 0 ; i<n ; i++)
    {
        if(i!=0 && v[i] == v[i-1]) continue;
        ll num = v[i];
        ll c1 = (x[0]==0 ? 0 : (x[0]<num)); 
        ll c2 = (x[1]==0 ? 0 : (x[1]<num));
        if(c1 < c2)
            x[0] = num;
        else if(c1 > c2)
            x[1] = num;
        else if(c1)
        {
            cost++;
            ll pos = 0;
            if(x[0] > x[1]) pos = 1;
            x[pos] = num; 
        }
        else
        {
            ll pos = 0;
            if(x[0] == 0) pos = 1;
            else pos = (x[0] < x[1] ? 0 : 1);
            x[pos] = num;
        }
    }

    cout << cost << "\n";
    
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}