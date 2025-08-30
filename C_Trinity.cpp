#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

void solve(ll tc_no)
{
	
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i = 0 ; i<n ; i++) cin >> v[i];
    
    sort(v.begin(), v.end());

    ll ans = INT_MAX;

    for(ll i = 0 ; i<n ; i++)
    {
        ans = min(n - (lower_bound(v.begin(), v.end(), v[i]*2) - v.begin()) + i, ans);
    }

    for(ll i = 1 ; i<n ; i++)
    {
        if(v[i] == v[i-1]) continue;
        ans = min(n-(lower_bound(v.begin(), v.end(), v[i] + v[i-1]) - v.begin()) + i - 1, ans);
    }

    cout << ans << "\n";
	
}

int main()
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