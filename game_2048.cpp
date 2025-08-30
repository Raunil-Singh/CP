// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define vll vector<long long>
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define MOD 998244353

vll solve()
{
    ll n = 5000000;
    vll ans(n, 0);
    map<ll, ll> intro;
    intro[4] = 4;
    for(ll i = 8 ; i<=n ; i*=2)
    {
        intro[i] = intro[i/2]*2 + i; 	
        // cout << "Intro : " << i << " " << intro[i] << "\n";
    }
    ans[0] = 1;
    
    for(ll i = 0 ; i<=n ; i++)
    {
        if(i%4 != 0) continue;
        for(ll j = 4 ; j<=i ; j*=2)
        {
            if(i - j - 2*intro[j/2] < 0) break;
            if(intro[j*2] >= i - j - (j>4 ? j : 0))
                ans[i] = (ans[i] + ans[i - j - 2*intro[j/2]])%MOD;
            else
                ans[i] = (ans[i] + ans[intro[j]])%MOD;
            // cout << i << " *** " << j << "\n";
            
        }
    }

    return ans;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	// For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vll ans = solve();

    ll t;
    cin >> t;

    for(ll  i = 0 ; i<t ; i++)
    {
        ll n;
        cin >> n;
        cout << ans[n] << "\n";
    }

	return 0;
}