#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

void solve(ll tc_no)
{
	
	ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i = 0 ; i<n ; i++) cin >> v[i];

    ll ans = (n%2 == 0 && v[n/2] == v[n/2-1]) ? 1 : 0;
    for(ll i = 1 ; i<=n-i-1 ; i++)
    {
        ll ans1 = ((v[i] == v[i-1]) ? 1 : 0) + ((v[n-i-1] == v[n-i]) ? 1 : 0), ans2 = ((v[i-1] == v[n-i-1]) ? 1 : 0) + ((v[i] == v[n-i]) ? 1 : 0);
        if(ans2 < ans1) swap(v[i], v[n-i-1]);
        ans += min(ans1, ans2);
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