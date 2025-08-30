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
    
    ll a[] = {0,0};
    for(ll i = 0 ; i<2*n ; i++)
    {
        ll temp;
        cin >> temp;
        a[temp]++;
    }

    ll ans1 = min(a[0], a[1]), ans2 = n - a[0]/2 - a[1]/2;

    cout << min(ans1, ans2) << " " << max(ans1, ans2) << "\n";
	
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