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
    
    ll n, k;
    cin >> n >> k;
    vector<int> v(n); inp(v);

    if(k>=3)
    {
        cout << "0\n";
        return;
    }
    if(k>=2)
    {
        set<int> s(all(v));
        sort(all(v));
        ll ans = v[0];
        for(ll i = 1 ; i<n ; i++)
        {
            for(ll j = 0 ; j<i ; j++)
            {
                if(s.find(v[i]-v[j])!=s.end())
                {
                    cout << "0\n";
                    return;
                }
                else
                {
                    ans = min(ans, v[i]-v[j]);
                    ll tar = v[i]-v[j];
                    ans = min(ans, *s.lower_bound(tar) - tar);
                    ll ind = upper_bound(all(v), tar) - v.begin();
                    if(ind != 0) ans = min(ans, abs(v[ind-1] - tar));
                }
            }
        }
        cout << ans << "\n";
        return;
    }
    sort(all(v));
    ll ans = v[0];
    for(ll i = 1 ; i<n ; i++) ans = min(ans, v[i]-v[i-1]);
    cout << ans << "\n";
    
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