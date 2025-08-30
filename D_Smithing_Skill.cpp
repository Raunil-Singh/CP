// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

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

const long double eps = 1e-12;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, m;
    cin >> n >> m;
    vector<int> a(n), b(n); inp(a); inp(b);
    vector<int> c(m); inp(c);

    vector<pair<int, int>> vp(n);
    for(ll i = 0 ; i<n ; i++)
        vp[i] = mpr(a[i]-b[i], a[i]);

    sort(all(vp));

    vector<pair<int, int>> con;
    for(auto p : vp) if(con.size()==0 || con.back().S > p.S) con.pb(p);
    
    vector<int> dp(con[0].S, 0);

    int curr = con.size()-1;
    for(int i = con.back().S ; i<con[0].S ; i++)
    {
        if(curr>0 && i>=con[curr-1].S) curr--;
        dp[i] = 1 + dp[i - con[curr].F];
    }

    int ans = 0;
    for(ll num : c)
    {
        int n = con[0].S <= num ? (num-con[0].S)/con[0].F + 1 : 0;
        ans += n + dp[num - n*con[0].F];
    }

    cout << ans*2 << "\n";
    
    return 0;
}