#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

class Solution
{
private :
    
    // Private functions and data members

    vector<pair<ll,ll>> data;
    map<ll, vector<ll>> adj;
    vector<bool> visited;

    vector<ll> result, result2;

    void set_data(ll node, ll depth)
    {
        visited[node] = true;
        ll successor_count = 0;
        ll max_depth = depth;
        for(ll next : adj[node])
        {
            if(visited[next]) continue;
            set_data(next, depth+1);
            successor_count += data[next].first;
            max_depth = max(max_depth, data[next].second);
        }
        data[node] = {successor_count + 1, max_depth};
        visited[node] = false;
    }

    void traverse(ll curr, ll prev, ll depth)
    {
        if(depth-1 >= 0)
            result2[depth-1]++;
        if(data[curr].second+1 < result.size())
            result[data[curr].second+1] += data[curr].first;
        if(data[prev].second+1 < result.size())
            result[data[prev].second+1] -= data[curr].first;
        for(ll next : adj[curr])
        {
            if(next == prev) continue;
            traverse(next, curr, depth+1);
        }
    }

public :
    void solve(ll tc_no)
    {

        ll n;
        cin >> n;

        data.assign(n, {0,0});
        visited.assign(n, false);

        for(ll i = 1 ; i<n ; i++)
        {
            ll a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        set_data(0,0);

        ll max_depth = data[0].second;

        result.assign(max_depth+1, 0);
        result2.assign(max_depth+1, 0);

        traverse(0, 0, 0);

        for(ll i = 1 ; i<=max_depth ; i++)
        {
            result[i] += result[i-1];
        }
        for(ll i = max_depth-1 ; i>=0 ; i--)
        {
            result2[i] += result2[i+1];
        }

        ll ans = INT_MAX;
        for(ll i = 0 ; i<=max_depth ; i++)
            ans = min(result[i]+result2[i], ans);
        
        cout << ans << "\n";
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