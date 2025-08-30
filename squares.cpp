#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	ull n, k, l;
	cin >> n >> k >> l;
	
	ull ans = n*(2*l)*(2*l);
	
	if(2*l > k) ans -= (n-1)*(2*l-k)*(2*l-k);

    cout << ans << "\n";

	return 0;
}