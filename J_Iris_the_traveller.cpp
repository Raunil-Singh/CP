#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

class Solution
{
private :
    
    // Private functions and data members
    vector<ll> v;

public :

    void recursion(vector<ll> &dele, vector<ll> &temp, ll sum, ll ind, ll &maxi, ll k)
    {
        // cout << ind << " " << sum << " ";
        if(ind >= v.size())
        {
            // cout << "1" << "\n";
            if(sum > maxi)
            {
                maxi = sum;
                dele = temp;
            }
            return;
        }
        if(v[ind] == 0)
        {
            // cout << "2" << "\n";
            recursion(dele, temp, sum, ind+1, maxi, k);
        
        }else
        {
            // cout << "3" << "\n";
            recursion(dele, temp, sum, ind+1, maxi, k);
            if(sum + v[ind] > k) return;
            temp.push_back(ind);
            recursion(dele, temp, sum + v[ind], ind+1, maxi, k);
            temp.pop_back();
        }
    }

    void solve(ll tc_no)
    {

        ll n , k;
        cin >> n >> k;

        v.assign(n, 0);

        for(ll i = 0 ; i<n ; i++)
        {
            ll len;
            cin >> len;
            v[len-1]++;
        }

        // cout << "***";
        // for(ll i : v)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        ll ans = 0;
        for(ll i = 0 ; i<n ; i++)
        {
            vector<ll> temp, dele;
            ll maxi = 0;
            recursion(dele, temp, 0, 0, maxi, k);
            if(dele.size() > 0)
            {
                ans++;
                for(ll indo : dele)
                    v[indo] = 0;
                // cout << ans << "**\n";
            }
        }
        
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
	
	// ll t;
	// cin >> t;
	// for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(0);
    }
	return 0;
}