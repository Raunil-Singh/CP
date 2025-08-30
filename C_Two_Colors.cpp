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
// use less_equal for multiple entries

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

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

int ncr(int n, int r)
{
    if(r > n) return 0;
    if(r == n || r == 0) return 1;
    return n*ncr(n-1, r-1) / r;
}

void solve(ll tc_no)
{
    
    int n, m;
    cin >> n >> m;
    vector<int> colors(m); inp(colors);

    vector<int> v(n+1, 0);
    for(int num : colors) v[num]++;
    for(int i = n-1 ; i>=0 ; i--) v[i] += v[i+1];


    
    int ans = 0;
    
    for(int i = 1 ; i<=n-i ; i++)
    {
        ans += (v[i]-v[n-i])*v[n-i] + ncr(v[n-i], 2)*(n-i != i ? 2 : 1);
    }

    cout << ans*2 << "\n";


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