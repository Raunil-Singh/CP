#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

void solve(ll tc_no)
{
	
	ll n, a, b;
    cin >> n >> a >> b;

    ll ran = gcd(a, b);

    set<ll> vals;
    vector<ll> v;
    for(ll i = 0 ; i<n ; i++)
    {
        ll temp;
        cin >> temp;
        if(vals.find(temp%ran) == vals.end())
        {
            vals.insert(temp%ran);
            v.push_back(temp%ran);
        }
    }

    if(v.size() == 1)
    {
        cout << "0\n";
        return;
    }

    sort(v.begin(), v.end());

    ll ans = v.back() - v.front();

    for(ll i = 1 ; i<v.size() ; i++)
        ans = min(ans, ran-(v[i]-v[i-1]));

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