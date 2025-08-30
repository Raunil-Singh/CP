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

    ll pos = 0;
    if(n&1)
    {
        cout << v[2]*(v[0] < 0 ? -1 : 1) << " " << v[2]*(v[1] < 0 ? -1 : 1) << " " << -(abs(v[1]) + abs(v[0])) << " ";
        pos+=3;
    }

    while(pos < n)
    {
        ll g = gcd(v[pos+1], v[pos]);
        cout << v[pos+1]/g << " " << -(v[pos]/g) << " ";
        pos+=2;
    }
	
    cout << "\n";
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