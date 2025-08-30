#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

class Solution
{
private :
    
    map<pair<set<ll>, ll>, ll> dp;
    vector<ll> a, b;

    ll solver(set<ll> &states, set<ll> &unvisited, ll curr)
    {
        if(dp.find({states, curr})!=dp.end()) return dp[{states, curr}];
        
        unvisited.erase(-curr);
        states.insert(-curr);

        ll ans = 0;
        ans = a[curr]+((unvisited.lower_bound((-curr))!=unvisited.end())?solver(states, unvisited, -(*(unvisited.lower_bound((-curr))))):0);
        

        if(unvisited.lower_bound((-b[curr]))!=unvisited.end())
            ans = max(ans, solver(states, unvisited, -(*(unvisited.lower_bound((-b[curr]))))));

        states.erase(-curr);
        unvisited.insert(-curr);
        return dp[{states, curr}] = ans;
    }

public :
    void solve(ll tc_no)
    {

        ll n;
        cin >> n;

        a.assign(n, 0);
        b.assign(n, 0);

        for(ll i = 0 ; i<n ; i++) cin >> a[i];
        for(ll i = 0 ; i<n ; i++)
        {
            ll num;
            cin >> num;
            b[i] = num-1;
        }

        set<ll> st, unvisited;
        for(ll i = 0 ; i<n ; i++) unvisited.insert(-i);
        solver(st, unvisited, 0);

        cout << dp[{st, 0}] << "\n";

    }
};

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
    {
        Solution obj;
        obj.solve(i);
    }
	return 0;
}