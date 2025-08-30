// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]

void solve(ll tc_no)
{
    
    ll  k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    int res = 1;
    ll ans = 0;
    for(ll num = 1 ; num*l1 <= r2 ; num*=k)
    {
        ll l = 0, r = r1+1;
        while(l+1 < r)
        {
            ll mid = (l+r)>>1;
            if(mid*num <= r2) l = mid;
            else r = mid;
        }
        // cout << "l = " << l << " # ";
        ll upper = l;
        l = 0, r = r2+1;
        while(l+1 < r)
        {
            ll mid = (l+r)>>1;
            if(mid*num < l2) l = mid;
            else r = mid;
        }
        // cout << "r = " << r << " # ";
        ll lower = min(max(r, l1), r1+1);
        res = max(upper-lower+1, 0ll);
        ans += res;
        // cout << lower << " " << upper << " # ";
        // cout << num << " " << res << " #\n";
    }
    cout << ans << "\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}