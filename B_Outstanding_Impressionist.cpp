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
    
    map<pair<int, int>, int> m;
    
    vector<bool> res(n, true);
    vector<int> v(2*n+1, 0); 
    vector<pair<int,int>> vp;

    for(ll i = 0 ; i<n ; i++)
    {
        ll a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        if(b-a == 0 && m.find(p)!=m.end())
        {
            res[m[p]] = false;
            res[i] = false; 
        }
        if(b-a == 0) v[b] = 1;
        m[p] = i;
        vp.pb(p);
    }

    for(ll i = 1 ; i<=2*n ; i++) v[i] += v[i-1];

    for(ll i = 0 ; i<n ; i++)
    {
        if(res[i] && (v[vp[i].S]-v[vp[i].F-1] != vp[i].S-vp[i].F+1 || vp[i].F == vp[i].S)) cout << 1;
        else cout << 0;
    }
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