#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

int get_least_set_bit(int num) {
    for(int i = 1 ; i<INT_MAX ; i<<=1) {
        if(num & i) return i;
    }
    return 0;
}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> v(n+1);
    
    for(int i = 1 ; i<r ; i++) {
        v[i] = get_least_set_bit(i);
    }
    for(int i = r+1 ; i<=n ; i++) {
        v[i] = get_least_set_bit(i - (r+1-l));
    }

    int x = *max_element(all(v));
    v[l] ^= (4*x);

    for(int i = l ; i<r ; i++) v[r] ^= v[i];

    for(int i = 1 ; i<=n ; i++) cout << v[i] << " ";
    cout << "\n";

}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:

    v[i] = least set bit of i , i<l
    l - r-1 => must contain the same
    r -> chosen to balance out l-(r-1)
    l must have an extra large set bit, maybe >=2*n
    pattern from r+1 must be treated as if it is from l+1
    
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
// Notebook  : y
// Using it? : y
// Sol Proof : done
// algo noted: yes
// Update the number of testcases: y
// Start coding ;)