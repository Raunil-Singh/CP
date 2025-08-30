#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

void solve(ll tc_no)
{
	
	ll n;
    cin >> n;

    bool flag = false;
    ll curr = 0;
    ll mh = INT_MIN;
    ll ah = INT_MIN;
    for(ll i = 0 ; i<n ; i++)
    {
        ll num;
        cin >> num;

        if(curr + num > 0)
        {
            curr += num;
            mh = max(curr, mh);
            ah = max(num, ah);
        }
        else
        {
            curr = max(num, 0ll);
            mh = max(num, 0ll);
            ah = max(num, 0ll);
        }
        
        // cout << i << " " << ah << " " << mh << "\n";

        if(mh > ah)
            flag = true;
        
    }

    cout << (flag ? "NO\n" : "YES\n");
	
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