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
#define MOD ((int)998244353)

void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, m;
    cin >> n >> m;
    vector<int> v(n); inp(v);

    auto compute = [](int prev, int curr, int net) -> int {
        int ans = 0;

        if(prev % curr != 0) return ans;

        int a = prev/curr, r = net/curr;

        vector<int> factors;
        int rem = a;
        for(int i = 2 ; i*i <= a ; i++) {
            if(rem % i == 0) {
                factors.push_back(i);
                while(rem % i == 0) rem /= i;
            }
        }

        if(rem > 1) factors.push_back(rem);

        int cnt = factors.size();
        int mask_cnt = (1<<cnt);

        for(int mask = 0 ; mask<mask_cnt ; mask++) {
            int curr = 1;
            for(int i = 0 ; i<cnt ; i++)
                if((mask>>i) & 1) curr *= factors[i];
            if(__builtin_popcount(mask) % 2 == 0) ans += r/curr;
            else ans -= r/curr;
        }

        return ans;
    };

    int ans = 1;
    for(int i = 1 ; i<n && ans ; i++) {
        ans *= compute(v[i-1], v[i], m) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";

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
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)