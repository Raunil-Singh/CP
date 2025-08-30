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

void solve(ll tc_no)
{
    
    ll n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    vector<int> v(n, -1);
    v[a] = 0;
    v[b] = 1;
    for(ll i = 0 ; i<n ; i++)
    {
        if(v[i]!=-1) continue;
        set<int> s;
        s.insert(v[(i+n-1)%n]);
        s.insert(v[(i+1)%n]);
        for(ll num = 0 ; num<5 ; num++)
        {
            if(s.find(num)==s.end())
            {
                v[i] = num;
                goto OUT;
            }
        }
        OUT:;
    }
    for(ll num : v) cout << num << " ";
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}