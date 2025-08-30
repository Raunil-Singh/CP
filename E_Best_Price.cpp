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
#define all(x) x.begin(), x.end()

void solve(ll tc_no)
{
    
    ll n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c; inp(n, a); inp(n, b);
    for(ll num : a) c.pb(num);
    for(ll num : b) c.pb(num);

    sort(all(a));
    sort(all(b));

    ll ans = 0;
    for(ll num : c)
    {
        ll tot = b.end()-lower_bound(all(b), num);
        ll pos = a.end()-lower_bound(all(a), num);
        if(tot-pos > k) continue;
        ans = max(ans, tot*num);
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

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}