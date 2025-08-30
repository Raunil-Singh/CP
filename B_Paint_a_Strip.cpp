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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<ll> res;
    res.pb(0);
    res.pb(1);
    while(res.back() < 100000)
        res.pb((res.back()+1)*2);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;
        ll l = 0, r = res.size()-1;
        while(l+1 < r)
        {
            ll mid = (l+r)/2;
            if(res[mid] >= n) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }

    return 0;
}