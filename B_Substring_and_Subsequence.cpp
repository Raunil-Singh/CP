// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]
#define all(x) x.begin(), x.end()

void solve(ll tc_no)
{
    
    string s1, s2;
    cin >> s1 >> s2;

    ll ans = s1.length() + s2.length();

    for(ll i = 0 ; i<s2.length() ; i++)
    {
        ll temp = i+s1.length();
        ll cp = i;
        for(char c : s1)
        {
            if(c == s2[cp])
            {
                cp++;
                if(cp == s2.length()) goto OUT;
            }
        }
        OUT:;
        ans = min(ans, (ll)(temp + s2.length()-cp));
    }

    cout << ans << "\n";

    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}