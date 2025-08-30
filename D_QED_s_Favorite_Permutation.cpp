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
    
    ll n, q;
    cin >> n >> q;
    vector<int> v(n); inp(v);
    string s;
    cin >> s;

    set<int> red_flag;
    vector<bool> sl(n, false), sr(n, false);

    ll max_num = 0;
    for(ll i = 0 ; i<n ; i++)
    {
        max_num = max(max_num, v[i]);
        sl[i] = (max_num == i+1);
    }

    ll min_num = 0;
    for(ll i = n-1 ; i>=0 ; i++)
    {
        min_num = min(min_num, v[i]);
        sr[i] = (min_num == i+1);
    }

    for(ll i = 0 ; i<n ; i++)
    {
        switch(s[i])
        {
            case 'L' : if(sl[i] == false) red_flag.insert()
        }
    }
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