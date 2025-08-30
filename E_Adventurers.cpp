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
    
    ll n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    
    vector<pair<int, int>> point(n);
    for(ll i = 0 ; i<n ; i++)
    {
        ll a, b;
        cin >> a >> b;
        x[i] = a;
        y[i] = b;
        point[i] = make_pair(a, b);
    } 

    sort(all(x)); sort(all(y));

    // Finding x_pos
    ll l = x[0], r = x[n-1];
    while(l<r)
    {
        ll mid = l+(r-l)/2;
        ll count = n - 2*(lower_bound(all(x), mid)-x.begin());
        if(count == 0) {l = mid, r = mid;}
        else if(count < 0) r = mid;
        else l = mid;
        cout << mid << " " << count << " x #\n";
    }

    ll x_pos = l;

    // Finding y_pos
    l = y[0]; r = y[n-1];
    while(l<r)
    {
        ll mid = l+(r-l)/2;
        ll count = n - 2*(lower_bound(all(y), mid)-y.begin());
        if(count == 0) {l = mid; r = mid;}
        else if(count < 0) r = mid;
        else l = mid;
        cout << mid << " " << count << " y #\n";
    }

    ll y_pos = l;

    vector<int> count(4, 0);
    for(pair<ll,ll> p : point)
    {
        if(p.F >= x_pos && p.S >= y_pos) count[0]++;
        else if(p.F >= x_pos) count[2]++;
        else if(p.S >= y_pos) count[1]++;
        else count[3]++;
    }

    cout << min(min(count[0], count[1]), min(count[2], count[3])) << "\n" << x_pos << " " << y_pos << "\n";
        
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

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