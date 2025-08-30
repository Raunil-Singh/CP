#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

void solve(ll tc_no)
{
	
    ll n;
    cin >> n;

    ll t = n%111;
    ll k = n/111;

    if((t%11 + k) >= 11 || t%11 == 0) cout << "YES\n";
    else cout << "NO\n";
	
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