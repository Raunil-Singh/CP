#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#define FAST_IO ;
#else
#define dbg(x, ...) ;
#define FAST_IO ios::sync_with_stdio(false); \
                cin.tie(nullptr);
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
#define MOD ((int64_t) 998244353)

inline void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;

    string s;
    cin >> s;

    // length, del, state
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(4)));
    dp[0][0][0] = 1;

    for(char curr : s) {
        dbg(curr);
        for(int l = n-1 ; l>=0 ; l--) {
            for(int del = (curr == ')') ; del <= n - (curr == '(') ; del++) {
                if(curr == '(') {
                    dp[l+1][del+1][0] = (dp[l+1][del+1][0] + dp[l][del][0]) % MOD;
                    dp[l+1][del+1][2] = (dp[l+1][del+1][2] + dp[l][del][1]) % MOD;
                    dp[l+1][del+1][3] = (dp[l+1][del+1][3] + dp[l][del][2] + dp[l][del][3]) % MOD;
                } else {
                    dp[l+1][del-1][1] = (dp[l+1][del-1][1] + dp[l][del][0] + dp[l][del][1]) % MOD;
                    dp[l+1][del-1][2] = (dp[l+1][del-1][2] + dp[l][del][2]) % MOD;
                    dp[l+1][del-1][3] = (dp[l+1][del-1][3] + dp[l][del][3]) % MOD;
                }
            }
        }
        // for(auto x : dp) dbg(x);
    }

    int ans = 0;
    for(int l = 1 ; l<=n ; l++) ans = (ans + dp[l][0][3] * (l-2)) % MOD;

    cout << ans << "\n";

}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    
    
****/

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    FAST_IO;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    cin >> t; // Update me!
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