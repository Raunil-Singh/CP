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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;

    vector<int> v(n); inp(v);

    vector<int> pref(n, 0), suff(n, 0);

    for(int i = 0 ; i<n-1 ; i++) pref[i+1] = pref[i]|v[i];
    for(int i = n-1 ; i>0 ; i--) suff[i-1] = suff[i]|v[i];

    if(n&1)
    {
        int ans = 0;
        for(int i = 0 ; i<n ; i++)
            ans = max(ans, pref[i]|suff[i]);
        cout << ans << "\n";
    }
    else
    {
        cout << (suff[0]|v[0]) << "\n";
    }


    
    return 0;
}