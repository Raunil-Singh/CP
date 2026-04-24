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

constexpr int inf = -10000000000LL;

inline void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> v(n); inp(v);
    
    int best = 0;
    for(int num : v) best += min(num % q % p, num % p);

    vector<int> vp(n);
    for(int i = 0 ; i<n ; i++) {
        vp[i] = v[i] % p - min(v[i] % q % p, v[i] % p);
        if(i>0) vp[i] += vp[i-1];
    }

    vector<int> vqp(n);
    for(int i = 0 ; i<n ; i++) {
        vqp[i] = v[i] % q % p - min(v[i] % q % p, v[i] % p);
        if(i>0) vqp[i] += vqp[i-1];
    }

    int min_del = min(vp[k-1], vqp[k-1]);
    for(int i = k ; i<n ; i++) {
        min_del = min(min_del, min(vp[i] - vp[i-k], vqp[i] - vqp[i-k]));
    }

    cout << best + min_del << "\n";

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