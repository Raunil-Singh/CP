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
#define all(x) x.begin(), x.end()

void solve(ll tc_no)
{
    
    ll n, m, q;
    cin >> n >> m >> q;

    ll a = 1, b = m, c = m, d = n;

    bool flag = true;

    for(ll i = 0 ; i<q ; i++)
    {
        ll num;
        cin >> num;
        if(flag && b==num && c==b)
        {
            a++;
            d--;
            flag = false;
            cout << min(n, a-1 + n-d) << " ";
            continue; 
        }
        if(flag)
        {
            if(num < a)
            {
                if(a<b) b--;
                if(c<d) d--;
            }
            else if(num < b) 
            {
                if(a<b && a>1) a++;
                if(a<b) b--;
                if(c<d && d<n) d--;
            }
            else if(num<=c)
            {
                if(a<b)a++;
                if(c<d)d--;
            }
            else if(num <= d)
            {
                if(a<b && a>1) a++;
                if(c<d) c++;
                if(c<d && d<n) d--;
            }
            else
            {
                if(a<b) a++;
                if(c<d) c++;
            }
            cout << min(n, a-1 + n-d + c-b+1) << " ";
        }
        else
        {
            if(num < a)
            {
                if(a<=d) d--;
            }
            else if(num > d) 
            {
                if(a<=d) a++;
            }
            else 
            {
                if(a<=d) a++;
                if(a<=d) d--;
            }
            cout << min(n, a-1 + n-d) << " ";
        }
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