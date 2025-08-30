// 10-06-2025 20:48:58 (IST +0530)
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

void dfs(int i, int j, vector<vector<int>>&g, vector<vector<bool>>&seen, int &curr, int k)
{
    if(seen[i][j]) return ;
    else seen[i][j] = true;
    curr++;
    if(i<g.size()-1 && abs(g[i][j] - g[i+1][j]) <= k) dfs(i+1, j, g, seen, curr, k);
    if(j<g[0].size()-1 && abs(g[i][j] - g[i][j+1]) <= k) dfs(i, j+1, g, seen, curr, k);
    if(i>0 && abs(g[i][j] - g[i-1][j]) <= k) dfs(i-1, j, g, seen, curr, k);
    if(j>0 && abs(g[i][j] - g[i][j-1]) <= k) dfs(i, j-1, g, seen, curr, k);
}

bool valid(int diff, vector<vector<int>>&g, int k)
{
    int longest = 0;
    int n = g.size(), m = g[0].size();
    vector<vector<bool>> seen(n, vector<bool>(m));
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(seen[i][j]) continue;
            int count = 0;
            dfs(i, j, g, seen, count, diff);
            // cout << count << " " << k << " # ";
            longest = max(longest, count);
        }
    }
    return longest >= k;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ":\n";
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n, vector<int>(m));
    for(vector<int> &v : g) inp(v);

    int l = -1, r = 2LL*INT_MAX;

    while(l+1 < r)
    {
        int mid = (l+r)/2;
        if(valid(mid, g, k)) r = mid;
        else l = mid;
    }

    cout << r << "\n";
    
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