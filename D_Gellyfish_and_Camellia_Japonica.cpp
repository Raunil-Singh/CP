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

#define inf 1000000000

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n, q;
    cin >> n >> q;
    vector<int> v(n); inp(v);

    vector<vector<int>> queries(q, vector<int>(3));
    for(vector<int>&x : queries) inp(x);

    reverse(all(queries));

    vector<int> upper = v;
    vector<int> lower = v;

    for(vector<int> &query : queries)
    {
        int x = query[0]-1, y = query[1]-1, z = query[2]-1;
        if(min(lower[x], lower[y]) > upper[z] || min(upper[x], upper[y]) < lower[z])
        {
            cout << "-1\n";
            return;
        }
        int lwr = lower[z];
        lower[x] = max(lower[x], lwr);
        lower[y] = max(lower[y], lwr);
        if(x == z) upper[x] = inf;
        else if(y == z) upper[y] = inf;
        else
        {
            lower[z] = 1;
            upper[z] = inf;
        }
    }

    for(int i = 0 ; i<n ; i++) cout << lower[i] << " ";
    cout << "\n";
    
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