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
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> r(n), s(m); inp(r); inp(s);
    string dir; cin >> dir;

    sort(all(s));

    unordered_map<int, unordered_map<int, int>> count;

    for(int p : r) {
        int right = (p < s.back()) ? (*lower_bound(all(s), p)) - p : INT_MAX;
        int left = (p > s[0]) ? (*(upper_bound(all(s), p)-1)) - p : INT_MIN;
        // cout << left << " " << p << " " << right << "\n";
        count[right][left]++;
        count[left][right]++;
    }

    dbg(count);

    int ans = 0;
    int curr = 0;
    for(char d : dir) {
        if(d == 'R') curr++;
        else curr--;
        dbg(count);
        if(count.find(curr) != count.end()) {
            for(auto & [a, b] : count[curr]) {
                ans += b;
                count[a][curr] -= b;
                if(count[a][curr] == 0) {
                    count[a].erase(curr);
                }

            }
        }
        count.erase(curr);
        cout << n - ans << " ";
    }

    cout << "\n";

}
// Note: Ensure all template parameters are update!

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