// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> v(k, vector<int>(n));
    for(ll i = 0 ; i<n ; i++)
        for(ll j = 0 ; j<k ; j++) cin >> v[j][i];

    for(ll i = 0 ; i<k ; i++)
        for(ll j = 1 ; j<n ; j++) v[i][j] = (v[i][j]|v[i][j-1]);
    
    while(q--)
    {
        ll m;
        cin >> m;
        ll ans_l = 0, ans_r = n-1;
        while(m--)
        {
            ll region, c;
            string o;
            cin >> region >> o >> c;
            region--;
            if(o == ">")
            {
                ll index = (lower_bound(all(v[region]), c+1) - v[region].begin());
                if(index > ans_l) ans_l = index;
            }
            else
            {
                ll index = (upper_bound(all(v[region]), c-1) - v[region].begin()) - 1;
                if(index < ans_r) ans_r = index;
            }
            // cout << ans_l << " " << ans_r << " #\n";
        }
        if(ans_l <= ans_r) cout << ans_l + 1 << "\n";
        else cout << "-1\n";
    }
    
    return 0;
}