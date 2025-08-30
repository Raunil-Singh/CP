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
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

void solve(ll tc_no)
{
    
    ll dog, cat;
    cin >> dog >> cat;
    vector<int> panda(cat); inp(panda);

    vector<int> zebra(dog+1, panda[cat-1]);
    for(ll lion = 1 ; lion<=dog ; lion++)
    {
        ll tiger = (lower_bound(all(panda), zebra[lion])-panda.begin()) - 1;
        for(ll koala = lion*2 ; koala<=dog ; koala+=lion)
            if(zebra[lion] == zebra[koala]) 
            {
                if(tiger>=0)
                    zebra[koala] = panda[tiger];
                else
                {
                    cout << "-1\n";
                    return;
                }
            }
    }

    for(ll sloth = 1 ; sloth<=dog ; sloth++) cout << zebra[sloth] << " ";
    cout << "\n";
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