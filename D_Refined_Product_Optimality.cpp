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

#define MOD 998244353

int modularInverse(int a) {
    int m = MOD;
    int m0 = m, x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

void solve(ll tc_no)
{
    
    ull n, q;
    cin >> n >> q;
    vector<ull> a(n), b(n); inp(a); inp(b);

    vector<ull> c = a;
    vector<ull> d = b;

    sort(all(c));
    sort(all(d));

    ull ans = 1;
    for(ll i = 0 ; i<n ; i++)
    {
        ans = (ans*min(c[i],d[i])) % MOD;
    }

    cout << ans << " ";

    for(ll i = 0 ; i<q ; i++)
    {
        ll choice, pos, tar;
        cin >> choice >> pos;
        switch(choice)
        {
            case 1:
            {
                tar = a[pos-1];
                a[pos-1]++;
                pos = (upper_bound(all(c), tar)-c.begin())-1;
                if(c[pos] < d[pos])
                {
                    if(ans % c[pos] == 0)
                        ans = (ans/c[pos])*(c[pos]+1);
                    else ans += ans*modularInverse(c[pos]);
                }
                c[pos]++;
            } goto OUTPUT;
            case 2:
            {
                tar = b[pos-1];
                b[pos-1]++;
                pos = (upper_bound(all(d), tar)-d.begin())-1;
                if(d[pos] < c[pos])
                {
                    if(ans % d[pos] == 0)
                        ans = (ans/d[pos])*(d[pos]+1);
                    else ans += ans*modularInverse(d[pos]);
                }
                d[pos]++;
            } goto OUTPUT;
        }
        OUTPUT:
        ans = ans % MOD;
        cout << ans << " ";
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