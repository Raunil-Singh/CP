#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

class Solution
{
private :
    
    set<pair<ll,ll>> used;
    map<ll, vector<ll>> adj;

    void dfs(ll curr, vector<ll> &colour, ll state)
    {
        bool flag = true;
        for(ll i : adj[curr])
        {
            if(used.find({min(i, curr), max(i, curr)})!=used.end() || colour[i]!=0) continue;
            if(flag && state == 0)
            {
                used.insert({min(i, curr), max(i, curr)});
                colour[i] = colour[curr];
                dfs(i, colour, 1);
                flag = false;
            }
            else
            {
                colour[i] = i;
                dfs(i, colour, 0);
            }
        }
    }

public :
    void solve(ll tc_no)
    {

        ll n;
        cin >> n;

        for(ll i = 1 ; i<n ; i++)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<vector<ll>> result;

        while(used.size() < n-1)
        {
            vector<ll> colouring(n+1, 0);
            for(ll i = 1 ; i<=n ; i++)
            {
                if(colouring[i] != 0) continue;
                colouring[i] = i;
                dfs(i, colouring, 0);

            }
            result.push_back(colouring);
        }

        cout << result.size() << "\n";
        for(ll i = 0 ; i<=result.size()-1 ; i++)
        {
            for(ll j = 1 ; j<=n ; j++)
                cout << result[i][j] << " ";
            cout << "\n";
        }

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