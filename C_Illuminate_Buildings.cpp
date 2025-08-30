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

    ll n;
    cin >> n;
    vector<int> v(n); inp(n, v);

    ll curr = -1;
    ll count = -1;
    ll ans = (n>0 ? 1 : 0);

    for(ll i = 1 ; i<n; i++)
    {
        for(ll t = 0 ; t<i ; t++)
        {
            ll curr = -1;
            ll count = -1;
            for(ll j = t ; j<n ; j+=i)
            {
                if(curr == v[j])
                {
                    count++;
                    ans = max(ans, count);
                }
                else
                {
                    count = 1;
                    curr = v[j];
                }
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}