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
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;

    vector<int> X(n); inp(X);

    set<int> all_x(all(X));

    all_x.insert(bx);

    map<int, int> min_y, max_y; // x -> smallest y, x-> largest y
    min_y[bx] = by;
    max_y[bx] = by;

    for(int i = 0 ; i<n ; i++) {
        int y; cin >> y;
        if(min_y.find(X[i]) == min_y.end()) {
            min_y[X[i]] = y;
            max_y[X[i]] = y;
        } else {
            min_y[X[i]] = min(min_y[X[i]], y);
            max_y[X[i]] = max(max_y[X[i]], y);
        }
    }

    int du = 0, dd = 0;
    int u = ay, d = ay;

    for(int x : all_x) {
        int new_du = min(du + max_y[x] - min_y[x] + abs(min_y[x] - u), dd + max_y[x] - min_y[x] + abs(min_y[x] - d));
        int new_dd = min(du + max_y[x] - min_y[x] + abs(max_y[x] - u), dd + max_y[x] - min_y[x] + abs(max_y[x] - d));
        u = max_y[x];
        d = min_y[x];
        du = new_du;
        dd = new_dd;
    }

    cout << bx - ax + min(du, dd) << "\n";


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