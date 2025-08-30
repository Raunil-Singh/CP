// 14-06-2025 16:22:36 (IST +0530)
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

void solve(ll tc_no)
{
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<m ; j++)
            cin >> v[i][j];
        
    vector<vector<int>> vmin(n+1, vector<int>(m+1, INT_MAX));
    vector<vector<int>> vmax(n+1, vector<int>(m+1, INT_MIN));

    vmax[n][m-1] = 0;
    vmin[n][m-1] = 0;

    for(int i = n-1 ; i>=0 ; i--)
    {
        for(int j = m-1 ; j>=0 ; j--)
        {
            vmax[i][j] = max(vmax[i+1][j], vmax[i][j+1]) + v[i][j];
            vmin[i][j] = min(vmin[i+1][j], vmin[i][j+1]) + v[i][j];
        }
    }

    // for(vector<int> &x : vmax)
    // {
    //     for(int num : x) cout << num << ' ';
    //     cout << "\n";
    // }

    // cout << "-------\n";

    // for(vector<int> &x : vmin)
    // {
    //     for(int num : x) cout << num << ' ';
    //     cout << "\n";
    // }

    if(vmax[0][0] >= 0 && vmin[0][0] <= 0 && vmax[0][0]%2 == 0) cout << "YES\n";
    else cout << "NO\n";
    
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