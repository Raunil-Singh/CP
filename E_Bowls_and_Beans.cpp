// 05-06-2025 16:54:13 (IST +0530)
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

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 1 ; i<n ; i++) cin >> c[i];
    set<int> a;
    for(int i = 1 ; i<n ; i++)
    {
        int num; cin >> num;
        if(num) a.insert(i);
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for(int i = 0 ; i<n ; i++) dp[i][i] = max(0LL, i);
    for(int i = 0 ; i<n ; i++)
        for(int j = i+1 ; j<n ; j++)
            if(dp[i][j-1] - c[dp[i][j-1]] > dp[j][j] - c[dp[j][j]]) dp[i][j] = dp[j][j];
            else dp[i][j] = dp[i][j-1];

    a.insert(0);

    int ans = 0;
    while(a.size() > 1)
    {
        int num = *a.rbegin();
        a.erase(num);
        ans++;
        if(num - c[num] <= 0) continue;
        if(a.lower_bound(num - c[num]) == a.end()) a.insert(dp[max(0LL, num - c[num])][num]);
    }

    cout << ans << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}