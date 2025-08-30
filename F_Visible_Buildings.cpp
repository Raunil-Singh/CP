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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // cout << fixed;
    cout << setprecision(18);

    ll n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(ll i = 0 ; i<n ; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    long double ans = -1.0;
    long double one = 1.0;

    for(ll i = 0 ; i<n-1 ; i++)
    {
        long double curr = v[i].S - ((long double)(v[i+1].S-v[i].S)*(v[i].F))/(long double)((v[i+1].F - v[i].F));
        ans = max(ans, curr);
        // cout << curr << " # ";
    }
    // cout << ans << "\n";
    cout << (ans >= 0.000000000 ? ans : (one*(-1))) << "\n";
    
    return 0;
}