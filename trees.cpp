// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second

void solve(ll tc_no)
{
	
    ll n, d, l;
    cin >> n >> d >> l;

	if(d == 1)
	{
		if(n == 2 && l == 2)
			cout << "1 2\n";
		else cout << "-1\n";
		return;
	}

	ll lowerb = (n-(d+1))/(d/2) + ((n-(d+1))%(d/2)!=0 ? 1 : 0);
	ll upperb = n-(d+1);
	if(lowerb > l-2 || upperb < l-2)
	{
		cout << -1 << "\n";
		return;
	}

	cout << "1 2" << "\n";
	int ma = 2;
	for(int i = 2 ; i<=d ; i++)
	{
		cout << ma << " " << ma+1 << "\n";
		ma++;
	}
	ma++;
	int mid = (d/2)+1;
	queue<ll> q;

	for(int i = 1 ; i<=l-2 ; i++)
	{
		cout << mid << " " << ma << "\n";
		q.push(ma);
		ma++;
	}

	while(ma<=n)
	{
		ll curr = q.front();
		q.pop();
		cout << curr << " " << ma << "\n";
		q.push(ma);
		ma++;
	}	
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	
	// For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	ll t;
	cin >> t;
	for(ll i = 1 ; i<=t ; i++)
		solve(i);

	return 0;
}