#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

void solve(ll tc_no)
{
	
	ll n, k;
    cin >> n >> k;

    if(n == 1)
    {
        cout << "1\n1\n";
        return;
    }
    if(k == 1 || k == n)
    {
        cout << "-1\n";
        return;
    }
    if(k%2 == 0)
    {
        cout << 3 << "\n";
        cout << 1 << " " << k << " " << k+1 << "\n";
        return;
    }
    else
    {
        cout << 5 << "\n";
        cout << 1 << " " << k-1 << " " << k << " " << k+1 << " " << n << "\n"; 
    }
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