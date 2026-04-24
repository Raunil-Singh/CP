#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>
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

void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    vector<pair<int, int>> res;

    function<void(int, int)> compute = [&](int l, int r) -> void {
        if(r-l <= 0) {
            res.push_back(make_pair(l, r));
            return;
        }
        for(int left = l ; left < r ; left++) {
            compute(left, r-1);
            if(left < r-1) res.push_back(make_pair(left+1, r-1));
        }
        res.push_back(make_pair(l, r));
    };
    function<void(int, int)> process = [&](int l, int r) -> void {
        if(l == r && v[l] != 0) return;
        res.push_back(make_pair(l, r));
        if(*min_element(v.begin()+l, v.begin()+r+1) == 0)
            res.push_back(make_pair(l, r));
        compute(l, r);
    };

    int net_sum = accumulate(all(v), (int)0);
    int left = 0;
    while(left < n) {
        int best = left-1;
        int sum = 0;
        int delb = 0;
        for(int i = left ; i<n ; i++) {
            sum += v[i];
            if((i-left+1)*(i-left+1) - sum > delb) {
                delb = (i-left+1)*(i-left+1) - sum;
                best = i;
            }
            // cout << left << " -> " << best << "\n";
        }
        net_sum += delb;
        if(left <= best) {
            cout << left << " - " << best << "\n";
            process(left, best);
        }
        left = max(left, best)+1;
    }

    cout << net_sum << " " << res.size() << "\n";

    // for(auto [a, b] : res) cout << a+1 << " " << b+1 << "\n";


}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:

    Okay, this works fine, need to develop a strategy to optimally decompose to get a good final solution.


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
// Notebook  : Yes
// Using it? : Yes
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)