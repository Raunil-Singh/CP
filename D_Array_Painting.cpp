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

    ll n;
    cin >> n;
    vector<int> v(n); inp(v);

    ll coin = 0;
    bool f[] = {false,false};
    for(ll num : v)
    {
        switch(num)
        {
            case 0:
            {
                f[0] = false;
                if(f[1] == true)
                {
                    f[1] = false;
                    continue;
                }
                coin++;
                f[0] = true; 
            } break;
            case 1:
            {
                if(f[0] == true)
                    continue;
                coin++;
                f[0] = true;
                f[1] = true; 
            } break;
            case 2:
            {
                if(f[0] == true || f[1] == true)
                {
                    f[0] = true;
                    f[1] = true;
                    continue;
                }
                coin++;
                f[0] = true;
                f[1] = true;
            } break;
        }
    }

    cout << coin << "\n";
    
    return 0;
}