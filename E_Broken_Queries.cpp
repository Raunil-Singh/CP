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
    
    ll n;
    cin >> n;

    ll l = 1, r = n;

    ll res;
    cout << "? 1 " << (n/2) << "\n";    
    cin >> res;

    ll lower = 1;

    if(res == 1)
    {
        int a, b;
        int response = 0;
        cout << "? 1 " << (n/4) << "\n";
        cin >> a;
        cout << "? " << (n/4) + 1 << " " << n/2 << "\n";
        cin >> b;
        if(a == 1 && b == 1)
        {
            l = 1;
            r = n/4;
        }
        else if(a == 0 && b == 0)
        {
            l = n/4;
            r = n/2;
        }
        else
        {
            l = n/2;
            r = n;
            response = 1;
        }
        
        while(l+1<r)
        {
            ll mid = (l+r)/2;
            cout << "? 1 " << mid << "\n";
            cin >> res;
            if(res == response) l = mid;
            else r = mid;
        }
        cout << "! " << r << "\n";
    }
    else
    {
        int a, b;
        int response = 0;
        cout << "? " << (n+1)-(n/4) << " " << (n+1)-1 << "\n";
        cin >> a;
        cout << "? " << (n+1)-(n/2) << " " << (n+1) - ((n/4) + 1) << "\n";
        cin >> b;
        if(a == 1 && b == 1)
        {
            l = n;
            r = (n+1)-n/4;
        }
        else if(a == 0 && b == 0)
        {
            l = (n+1)-n/4;
            r = (n+1)-n/2;
        }
        else
        {
            l = (n+1)-n/2;
            r = (n+1)-n;
            response = 1;
        }
        
        while(r+1<l)
        {
            ll mid = (l+r)/2;
            cout << "? " << mid << " " << n << "\n";
            cin >> res;
            if(res == response) l = mid;
            else r = mid;
        }
        cout << "! " << (n+1)-r << "\n";
    }
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}