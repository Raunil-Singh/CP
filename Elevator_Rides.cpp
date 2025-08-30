// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, x;
    cin >> n >> x;
    vector<ll> v(n); inp(v);

    ll mask_count = 1<<n;

    vector<int> dp1(mask_count, n);
    vector<int> dp2(mask_count, x);

    dp1[0] = 0;
    
    for(ll mask = 1 ; mask<mask_count ; mask++)
    {
        for(ll i = 0 ; i<n ; i++)
        {
            ll prev_mask = mask^(1<<i);
            if(prev_mask != mask)
            {
                ll a = dp1[prev_mask] + (dp2[prev_mask] + v[i] > x);
                ll b = (dp2[prev_mask] + v[i] > x ? v[i] : (dp2[prev_mask] + v[i]));
                if(a<dp1[mask] || (a==dp1[mask] && b<dp2[mask]))
                {
                    dp1[mask] = a;
                    dp2[mask] = b;
                }
            }
        }
    }
    
    cout << dp1[mask_count-1] << "\n";
    
    return 0;
}