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
    
    ll n, k;
    cin >> n >> k;

    if(n-1 < log2(k))
    {
        cout << "-1\n";
        return;
    }

    vector<ll> v;
    ll num = k-1;
    for(ll i = 1 ; i<n ; i++)
    {
        v.pb(num%2);
        num/=2;
    }
    reverse(v.begin(), v.end());

    vector<int> res(n);
    num = 1;

    int f = 0, b = n-1;
    for(ll pos : v)
    {
        if(pos == 0)
            res[f++] = num++;
        else res[b--] = num++;
    }
    res[b] = num;

    for(ll i : res)
    {
        cout << i << " ";
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