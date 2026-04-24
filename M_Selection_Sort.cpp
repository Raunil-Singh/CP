#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <unordered_map>
using namespace __gnu_pbds;
using namespace std;

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
    vector<int> sa = v; sort(all(sa));
    unordered_map<int, int> mpp;
    for(int i = 0 ; i<n ; i++) {
        if((!i) || sa[i] != sa[i-1]) mpp[sa[i]] = i;
    }

    vector<int> pos(n+1);
    for(int i = 1 ; i<=n ; i++) pos[i] = ++mpp[v[i]];
    
    int l = 0, r = n+1;

}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    sort array and number elements.

    traverse left to right to see what is found stuff. Unfound + Unseen handled in reverse dir.
    
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
// Notebook  : yes
// Using it? : yes
// Sol Proof : yes
// algo noted: 
// Update the number of testcases: done
// Start coding ;)