#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define mod 1000000007LL

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	string s;
    cin >> s;

    ull p1 = 131;
    ull p2 = 211;
    ull h11 = 0, h12 = 0;
    ull h21 = 0, h22 = 0;
    ull ptr1 = 0;

    ll pos = -100;
    ull n = s.length();
    ull p1_ = 1;
    ull p2_ = 1;
    for(ll i = 0 ; i<n ; i++)
    {
        h11 = (h11 + s[i]*p1_) % mod;
        h12 = (h12 + s[i]*p2_) % mod;
        p1_ = (p1*p1_)%mod;
        p2_ = (p2*p2_)%mod;

        h21 = (s[n-i-1] + h21*p1) % mod;
        h22 = (s[n-i-1] + h22*p2) % mod;
        if(i >= n-i-1 && h11==h21 && h12 == h22)
        {
            pos = n-i-1;
            break;
        }
        // cout << h11 << " " << h21 << " " << i << " " << n-i-1 << "\n";
    }

    if(pos == -100 || pos == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for(ll i = pos ; i<n ; i++)
            cout << s[i];
        cout << "\n";
    }
	return 0;
}