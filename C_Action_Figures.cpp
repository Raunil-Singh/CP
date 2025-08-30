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
#define pf(x) push_front(x)
#define ppf(x) pop_front(x)
#define F first
#define S second

void solve(ll tc_no)
{
	
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    queue<ll> q;
    for(ll i = n-1 ; i>=0 ; i--)
    {
        if(s[i] == '0')
        {
            ans += i+1;
            if(!q.empty()) q.pop();
        }
        else if(s[i] == '1')
            q.push(i+1); 
    }
    ll pc = (q.size()/2);
    while(pc--)q.pop();
    while(!q.empty())
    {
        ans += q.front();
        q.pop();
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