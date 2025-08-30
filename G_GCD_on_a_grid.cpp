// 03-06-2025 14:29:28 (IST +0530)
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

bool traverse(vector<vector<int>> &v, vector<vector<int>> &dp, int n , int m, int ans)
{
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(i+j > 0) dp[i][j] = 0; 
            if(v[i][j] % ans != 0) continue;
            if(i>0) dp[i][j] |= dp[i-1][j];
            if(j>0) dp[i][j] |= dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": \n";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(vector<int>&temp : v) inp(temp);

    int max_gcd = gcd(v[0][0], v[n-1][m-1]);
    vector<int> factors;
    for(int i = 1 ; i*i<=max_gcd ; i++)
    {
        if(max_gcd % i != 0) continue;
        factors.pb(i);
        factors.pb(max_gcd/i);
    }
    int ans = 1;
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;
    for(int num : factors)
        if(traverse(v, dp, n, m, num)) ans = max(num, ans);
    
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