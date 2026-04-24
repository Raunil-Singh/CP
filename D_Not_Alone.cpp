#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#define FAST_IO ;
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
#define MOD ((int64_t) 998244353)

inline void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    auto compute = [&](int ind) -> int {
        vector<int> cst(n, -1);

        cst[ind] = INT_MAX;
        cst[(ind+1) % n] = abs(v[ind] - v[(ind+1) % n]);
        cst[(ind+2) % n] = max(max(v[ind], v[(ind+1) % n]), v[(ind+2) % n]) - min(min(v[ind], v[(ind+1) % n]), v[(ind+2) % n]);

        for(int i = (ind+3) % n ; cst[i] == -1 ; i = (i+1) % n) {
            int c2 = cst[(i-2+n) % n] + abs(v[i] - v[(i-1+n) % n]);
            int c3 = cst[(i-3+n) % n] + max(max(v[i], v[(i-1+n) % n]), v[(i-2+n) % n]) 
                                      - min(min(v[i], v[(i-1+n) % n]), v[(i-2+n) % n]);
            cst[i] = min(c2, c3);    
        }
        dbg(cst);
        return max(cst[(ind-1+n) % n], (int)0);
    };

    int ans = compute(1);
    dbg(ans);
    ans = min(ans, compute(2));
    dbg(ans);
    ans = min(ans, compute(0));
    dbg(ans);
    
    cout << ans << "\n";

}
// Note: Ensure all template parameters are updated!

/****              Algorithm keypoints:
    here:
    
    
    
****/

int32_t main() {
    #ifdef BG
    auto begin = std::chrono::high_resolution_clock::now();
    #else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    #ifdef BG
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif

    return 0;
}


// ======= CHECKLIST =======
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)