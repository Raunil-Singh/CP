#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#else
#define dbg(x, ...) ;
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

int dp[31][1001];

inline void preprocessing() {

    int n = 30, k = 1000;

    for(int i = 1 ; i<=n ; i++) {
        dp[i][0] = i;
    }
    
    for(int i = 1 ; i<=n ; i++) {
        for(int j = 1 ; j<=k ; j++) {
            for(int t = 1 ; t<i && t*(i-t) <= j ; t++) {
                if(dp[i-t][j - t*(i-t)] != 0) {
                    dp[i][j] = t;
                    goto NEXT;
                }
            }
            NEXT:;
        }
    }

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, k;
    cin >> n >> k;

    if(dp[n][k] == 0) {
        cout << "0\n";
        return;
    }

    vector<vector<int>> res;
    int rem = k;
    int pos = n;
    int curr = 1;
    while(dp[pos][rem]) {
        
        int num = dp[pos][rem];
        vector<int> temp;
        while(num--) temp.push_back(curr++);
        res.push_back(temp);
        
        int n_rem = rem - dp[pos][rem] * (pos - dp[pos][rem]);
        int n_pos = pos - dp[pos][rem];
        rem = n_rem;
        pos = n_pos;
    }

    reverse(all(res));

    for(auto &temp : res) {
        for(int num : temp) cout << num << " ";
    }
    cout << "\n";


}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    
    
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
    cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


// ======= CHECKLIST =======
// Notebook  : Y
// Using it? : Y
// Sol Proof : Y
// algo noted: In notes
// Update the number of testcases: Y
// Start coding ;)