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
    
    ll n;
    cin >> n;
    vector<int> a(n), b(n); inp(a); inp(b);

    ll x[] = {0,0};
    ll sub = 0, add = 0;

    for(ll i = 0 ; i<n ; i++)
    {
        if(a[i] == b[i])
        {
            if(a[i] == 1) add++;
            else if(a[i] == -1) sub++;
        }
        else
        {
            if(a[i] > b[i]) x[0] += a[i];
            else x[1] += b[i];
        }
    }

    while(sub--)
        if(x[0] > x[1]) x[0] --;
        else x[1]--;

    while(add--)
        if(x[0] < x[1]) x[0]++;
        else x[1]++;
    
    cout << min(x[0], x[1]) << "\n";

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