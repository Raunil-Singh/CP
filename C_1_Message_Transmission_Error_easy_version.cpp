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

	string s;
    cin >> s;

    ll pos = -100;
    for(ll i = 1 ; i<(s.length()+1)/2 ; i++)
    {
        for(ll j = 0 ; j+i<=s.length() ; j++)
        {
            if(j+i == s.length())
            {
                pos = i;
                goto out;
            }
            if(s[i+j]!=s[j]) break;
        }
    }
    out:;

    if(pos==-100) cout << "NO\n";
    else{
        cout << "YES\n";
        while(pos < s.length())
        {
            cout << s[pos];
            pos++;
        }
    }

	return 0;
}