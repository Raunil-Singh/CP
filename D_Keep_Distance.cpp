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

void solve(ll curr, ll n, ll m, vector<ll> &v, vector<vector<ll>>&res)
{
    if(n == 0)
    {
        res.pb(v);
        return;
    }

    for(ll i = curr ; i <= m - (n-1)*10 ; i++)
    {
        v.pb(i);
        solve(i+10, n-1, m, v, res);
        v.ppb();
    }

}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// For IO in txt file
    freopen("input.txt", "r", stdin);

	ll n, m;
    cin >> n >> m;
    vector<ll> v;
    vector<vector<ll>> res;

    solve(1, n, m, v, res);

    cout << res.size() << "\n";
    for(vector<ll> ans : res)
    {
        for(ll i : ans)
            cout << i << " ";
        cout << "\n";
    }

	return 0;
}