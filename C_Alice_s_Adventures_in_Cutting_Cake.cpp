#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>
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
    
    // cout << "Case #" << tc_no << ":\n";
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> v(n); inp(v);

    vector<int> pref(m+1, -1);
    vector<int> suff(m+1, -1);

    pref[0] = 0;
    suff[0] = 0;

    int sum = accumulate(all(v), (int)0);

    int pos = 1, curr = 0;
    for(int i = 0 ; i<n && pos <= m ; i++) {
        curr += v[i];
        if(curr >= r) {
            pref[pos] = curr + pref[pos-1];
            curr = 0;
            pos++;
        }
    }

    // for(int num : pref) cout << num << " ";
    // cout << "\n";

    reverse(all(v));

    pos = 1; curr = 0;
    for(int i = 0 ; i<n && pos <= m ; i++) {
        curr += v[i];
        if(curr >= r) {
            suff[pos] = curr + suff[pos-1];
            curr = 0;
            pos++;
        }
    }

    // for(int num : suff) cout << num << " ";
    // cout << "\n";

    if(pref[m] == -1 || suff[m] == -1) {
        cout << "-1\n";
        return;
    }

    int ans{};

    for(int i = 0 ; i<=m ; i++) {
        ans = max(ans, sum - (pref[i] + suff[m-i]));
    }

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