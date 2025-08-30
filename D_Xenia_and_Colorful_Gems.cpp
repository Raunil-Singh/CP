// 03-06-2025 00:49:50 (IST +0530)
// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void preprocessing()
{

    // Code here

}

int compute(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int x = a.size(), y = b.size(), z = c.size();
    int ans = LLONG_MAX;
    int na = -100, nc = -100;
    int i = 0, j = 0;
    while(i<x || j<z)
    {
        if(j>=z || (i<x && a[i] < c[j]))
        {
            na = a[i];
            i++;
        }
        else
        {
            nc = c[j];
            j++;
        }
        if(na == -100 || nc == -100) continue;
        int n1 = lower_bound(all(b), (na+nc)/2 + 1) - b.begin();
        if(n1 < y) ans = min(ans, (na - nc)*(na - nc) + (na - b[n1])*(na - b[n1]) + (nc - b[n1])*(nc - b[n1]));
        if(n1 > 0) ans = min(ans, (na - nc)*(na - nc) + (na - b[n1-1])*(na - b[n1-1]) + (nc - b[n1-1])*(nc - b[n1-1]));
    }
    return ans;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> a(x), b(y), c(z); inp(a); inp(b); inp(c);

    sort(all(a));
    sort(all(b));
    sort(all(c));

    int ans = compute(a, b, c);
    ans = min(ans, compute(a, c, b));
    ans = min(ans, compute(c, a, b));

    cout << ans << "\n";
    
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}