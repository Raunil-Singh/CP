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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	vector<ll> v(3*100000, -1);

    ll n, m;
    cin >> n >> m;

    ll pos = v.size()-1;
    for(ll i = 0 ; i<n ; i++)
    {
        ll num;
        cin >> num;
        while(num <= pos) v[pos--] = i+1;
    }

    for(ll i = 0 ; i<m ; i++)
    {
        ll num;
        cin >> num;
        cout << v[num] << "\n";
    }

	return 0;
}