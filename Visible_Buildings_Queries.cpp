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
    int n, q;
    cin >> n >> q;

    vector<int> v(n); inp(v); v.push_back(INT_MAX);
    vector<vector<int>> par(30, vector<int>(n+1, n));

    stack<int> st;
    for(int i = 0 ; i<n ; i++) {
        while(!st.empty() && v[st.top()] < v[i]) {
            par[0][st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    for(int lvl = 1 ; lvl < 30 ; lvl++) {
        for(int i = 0 ; i<n ; i++) {
            par[lvl][i] = par[lvl-1][par[lvl-1][i]];
        }
    }

    while(q--) {
        int ans = 1;
        int a, b; cin >> a >> b;
        a--; b--;
        int curr = a;
        int del = 29;
        while(del >= 0) {
            if(par[del][curr] <= b) {
                curr = par[del][curr];
                ans += (1<<del);
            }
            del--;
        }
        cout << ans << "\n";
    }

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
    // cin >> t; // Update me!
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