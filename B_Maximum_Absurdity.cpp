#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#else
#define dbg(x) ;
#endif

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

#define int int64_t // upto 9.2 * (10^18)
#define uint uint64_t // upto 1.8 * (10^19)
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, k;
    cin >> n >> k;

    vector<int> sum (2*n+1);
    for(int i = 0 ; i<n ; i++) cin >> sum[i];
    for(int i = n-1 ; i>=0 ; i--) sum[i] += sum[i+1];

    vector<int> dp (2*n+1);
    for(int i = 0 ; i<=2*n ; i++) dp[i] = i;

    for(int i = n-k ; i>=0 ; i--) {
        if(sum[dp[i]] - sum[dp[i]+k] < sum[dp[i+1]] - sum[dp[i+1] + k]) {
            dbg(sum[dp[i]] - sum[dp[i]+1]);
            dp[i] = dp[i+1];
        }
    }
    // for(int i = 0 ; i<n ; i++) cout << dp[i] << " ";
    // cout << "\n";

    int ans = 0;
    int a = 0, b = k;
    for(int i = 0 ; i<=n-k ; i++) {
        if(ans < sum[i] - sum[i+k] + sum[dp[i+k]] - sum[dp[i+k]+k]) {
            ans = sum[i] - sum[i+k] + sum[dp[i+k]] - sum[dp[i+k]+k];
            a = i;
            b = dp[i+k];
        }
    }

    cout << a+1 << ' ' << b+1 << "\n";

}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    dp from back to front then from front to back
    
****/

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    // cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


// ======= CHECKLIST =======
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)