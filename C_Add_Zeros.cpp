#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

class Solution
{
private :
    
    // Private functions and data members
    map<ll, vector<ll>> m;
    ll max_length;

    void depth(ll curr)
    {
        max_length = max(curr, max_length);
        for(ll i = 0 ; i<m[curr].size() ; i++)
        {
            if(m[curr][i] == -1) continue;
            depth(m[curr][i]);
            m[curr][i] = -1;
        }
    }

public :
    void solve(ll tc_no)
    {

        ll n;
        cin >> n;

        max_length = INT_MIN;

        vector <ll> v(n); for(ll i = 0 ; i<n ; i++) cin >> v[i];

        for(ll i = 1 ; i<n ; i++)
            m[v[i] + i].push_back(v[i] + 2*i);
        
        depth(n);

        cout << max_length << "\n";

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