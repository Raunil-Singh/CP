#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <type_traits>
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

    vector<int> zero;
    zero.push_back(-1);
    for(int i = 0 ; i<n ; i++) {
        if(!v[i]) zero.push_back(i);
    }

    zero.push_back(n);

    // returns (left_rem, right_rem)
    function<pair<int, int>(int, int)> compute = [&](int l, int r) -> pair<int, int> {

        int neg_count = 0;
        for(int i = l ; i<=r ; i++) if(v[i] < 0) neg_count++;

        if(neg_count % 2 == 0) {
            return make_pair(0, 0);
        }

        // cout << neg_count << "**\n";

        int del1 = 0, rem1 = 0;
        for(int i = l ; i<=r ; i++) {
            if(abs(v[i]) == 2) del1++;
            if(v[i] < 0) {
                rem1 = i - l + 1;
                break;
            }
        }

        int del2 = 0, rem2 = 0;
        for(int i = r ; i>=l ; i--) {
            if(abs(v[i]) == 2) del2++;
            if(v[i] < 0) {
                rem2 = r - i + 1;
                break;
            }
        }

        // cout << del1 << " " << del2 << "\n";
        if(del1 <= del2) return make_pair(rem1, 0);
        else return make_pair(0, rem2);

    };

    int prod = INT_MIN;
    int l = 0, r = 0;

    for(int i = 0 ; i<zero.size()-1 ; i++) {
        int curr = 0;
        auto [a, b] = compute(zero[i]+1, zero[i+1]-1);
        for(int ind = zero[i] + 1 + a ; ind <= zero[i+1]-b-1 ; ind++) {
            if(abs(v[ind]) == 2) curr++;
        }
        // cout << zero[i] << " " << a << " " << curr << " " << b << " " << zero[i+1] << "\n";
        if(prod < curr) {
            prod = curr;
            l = zero[i] + a + 1;
            r = n - zero[i+1] + b;
        }
    }

    cout << l << " " << r << "\n";

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