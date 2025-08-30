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

int ternary_search(int k, vector<int>&v1, vector<int>&v2) {
    int l = 0, r = k;
    int m = v1.size(), n = v2.size();

    auto f = [&v1, &v2, &m, &n](int num, int k)
    {
        if(num < m) return v1[num-1] + v2[k-num-1];
    };

    while (l<r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = f(m1);      //evaluates the function at m1
        int f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<int> deg(n, 0);
    set<pair<int, int>> edge;
    for(ll i = 1 ; i<n ; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        edge.insert(mpr(a, b));
        edge.insert(mpr(b, a));
    }

    if(n==2)
    {
        cout << "0\n";
        return;
    }


    vector<pair<int, int>> vp(n);
    for(ll i = 0 ; i<n ; i++)
        vp[i] = mpr(deg[i], i);
    
    sort(all(vp));
    reverse(all(vp));

    ll ans = vp[0].F + vp[1].F - 1 - (edge.find(mpr(vp[0].S, vp[1].S))!=edge.end() ? 1 : 0);
    ans = max(ans, vp[0].F + vp[2].F - 1 - (edge.find(mpr(vp[0].S, vp[2].S))!=edge.end() ? 1 : 0));
    ans = max(ans, vp[1].F + vp[2].F - 1 - (edge.find(mpr(vp[1].S, vp[2].S))!=edge.end() ? 1 : 0));

    cout << ans << "\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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