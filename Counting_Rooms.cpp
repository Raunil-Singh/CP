#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)

class Solution
{
private :
    
    // Private functions and data members
    vector<string> grid;
    ll n, m;
    void dfs(ll i, ll j)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == '#') return;
        grid[i][j] = '#';
        dfs(i+1, j);
        dfs(i-1, j);
        dfs(i, j-1);
        dfs(i, j+1);
    }

public :
    void solve(ll tc_no)
    {
        cin >> m >> n;

        for(ll i = 0;  i<m ; i++)
        {
            string s;
            cin >> s;
            grid.pb(s);
        }

        ll counter = 0;
        for(ll i = 0 ; i<m ; i++)
        {
            for(ll j = 0 ; j<n ; j++)
            {
                if(grid[i][j] == '#') continue;
                counter++;
                dfs(i, j);
            }
        }

        cout << counter << "\n";
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
	
	// ll t;
	// cin >> t;
	// for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(0);
    }
	return 0;
}