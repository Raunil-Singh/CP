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
    
    ll n, m;
    cin >> n >> m;
    vector<int> a(n), b(m); inp(n, a); inp(m, b);

    ll k = a[0];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> rank(m);
    for(ll i = 0 ; i<m ; i++)
    {
        if(k>=b[i]) rank[i] = 1;
        else
        {
            rank[i] = n-(lower_bound(a.begin(), a.end(), b[i])-a.begin())+1;
            if(rank[i] == 0) rank[i] = 1;
        }
    }

    sort(rank.begin(), rank.end());

    for(ll i = 1 ; i<=m ; i++)
    {
        ll sum = 0;
        for(ll j = i-1 ; j<m ; j+=i)
            sum += rank[j];
        cout << sum << " ";
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}