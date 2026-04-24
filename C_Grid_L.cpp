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

int compute_sqrt(int t) {
    int l = 0, r = t+1;
    while(l+1 < r) {
        int mid = (l+r)/2;
        if(mid * mid < t) l = mid;
        else r = mid;
    }
    return r;
}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int p, q;
    cin >> p >> q;

    int t = p + 2*q;

    int n_cap = compute_sqrt(2*t + 1)/2;

    // cout << "t   : " << t << "\n";
    // cout << "Cap : " << n_cap << "\n";

    for(int n = 1 ; n<=n_cap && n < t ; n++) {
        if((t-n) % (n*2 + 1)) continue;
        int m = (t-n)/(n*2 + 1);
        if(m < n) break;
        int l = 0;
        if(n == 1) l = m + 1;
        else l = n*m + 2;
        // cout << m << " " << n << " " << l << "\n";
        if(q <= l) {
            cout << n << " " << m << "\n";
            return;
        }
    }

    cout << "-1\n";

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