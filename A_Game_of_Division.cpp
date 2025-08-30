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
    vector<int> v(n); inp(n, v);

    vector<int> vk(k, 0);
    for(ll num : v) vk[num%k]++;

    bool flag = false;
    ll t;
    for(ll i = 0 ; i<k ; i++)
        if(vk[i] == 1)
        {
            t = i;
            flag = true;
            break;
        }
    if(!flag)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(ll i = 0 ; i<n ; i++)
    {
        if(v[i]%k == t)
        {
            cout << i+1 << "\n";
            return;
        }
    }
    
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