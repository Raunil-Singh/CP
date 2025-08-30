#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

void solve(ll tc_no)
{
	
	ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for(ll i = 0 ; i<n ; i++) cin >> v[i];

    sort(v.begin(), v.end());

    ll ans = 0;
    ll curr_step = 0;

    for(ll i = 0; i<n && k>0 ; i++)
    {
        if((v[i] - curr_step)*(n-i) >= k)
        {
            ans += k;
            k -= k;
        }
        else
        {
            ans += 1 + (v[i]-curr_step)*(n-i);
            k -= (v[i]-curr_step)*(n-i);
        }
        curr_step = v[i];
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