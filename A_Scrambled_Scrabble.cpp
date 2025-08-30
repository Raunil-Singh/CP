// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    string s;
    cin >> s;

    ll v = 0, y = 0, n = 0, g = 0, a = 0;
    for(char c : s)
    {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') v++;
        else if(c == 'N') n++;
        else if(c == 'G') g++;
        else if(c == 'Y') y++;
        else a++; 
    }

    // cout << v << " " << y << " " << n << " " << g << " " << a << " # \n";

    if(g>n) swap(n, g);

    ll res = 0;
    for(ll t = 0 ; t<=g ; t++)
    {
        for(ll k = 0 ; k<=y ; k++)
        {
            ll conso = a+n+t+k;
            ll vowel = v+y-k;
            ll count = min(vowel, conso/2);
            ll ans = count;
            count*=2;
            ll temp = min(count, g-t);
            ans += temp*2;
            count -= temp;
            ans += min(count, n-temp+g-temp+k+a);
            res = max(ans, res);
            // cout << t << " " << k << " " << ans << "#\n";
        }
    }

    cout << res << "\n";
    
    return 0;
}