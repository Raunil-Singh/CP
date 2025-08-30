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

int find_set(int v, vector<int> &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if(a>b) swap(a, b);
    parent[b] = a;
}

void solve(ll tc_no)
{
    
    ll n, m1, m2;
    cin >> n >> m1 >> m2;

    ll ans = 0;

    vector<pair<int, int>> f;
    for(ll i = 0 ; i<m1 ; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a>b) swap(a, b);
        f.pb(mpr(a, b));
        // cout << "F: " << a << " " << b << "\n";
    }

    vector<int> pg(n);
    for(ll i = 0 ; i<n ; i++) pg[i] = i;
    
    vector<pair<int, int>> g;
    
    for(ll i = 0 ; i<m2 ; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a>b) swap(a, b);
        g.pb(mpr(a, b));
        union_sets(a, b, pg);
        // cout << "G: " << a << " " << b << "\n";
    }

    vector<pair<int, int>> temp;
    for(ll i = 0 ; i<m1 ; i++)
    {
        if(find_set(f[i].F, pg) == find_set(f[i].S, pg))
            temp.pb(f[i]);
        else ans++;
        // cout << f[i].F << " " << f[i].S << " " << ans << "#\n";
    }
    f = temp;
    m1 = f.size();

    vector<int> pf(n);
    for(ll i = 0 ; i<n ; i++) pf[i] = i;

    for(ll i = 0 ; i<m1 ; i++)
        union_sets(f[i].F, f[i].S, pf);
    
    for(ll i = 0 ; i<m2 ; i++)
    {
        if(find_set(g[i].F, pf) != find_set(g[i].S, pf))
        {
            ans++;
            union_sets(g[i].F, g[i].S, pf);
        }
        // cout << g[i].F << " " << g[i].S << " " << ans << "?\n";
    }

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