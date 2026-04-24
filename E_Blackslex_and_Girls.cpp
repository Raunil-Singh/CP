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
    int n, x, y;
    cin >> n >> x >> y;
    string s; cin >> s;
    vector<int> p(n); inp(p);

    int buff_x = 0, buff_y = 0;
    bool x_req = false, y_req = false;
    int x_heavy = 0, y_heavy = 0;
    
    for(int i = 0 ; i<n ; i++) {
        if(s[i] == '0') {
            x_req = true;
            x--;
            p[i]--;
            if(p[i] % 2 == 1) {
                p[i]--;
                x--;
                buff_x++;
            }
            x_heavy += p[i];
        } else {
            y_req = true;
            y--;
            p[i]--;
            if(p[i] % 2 == 1) {
                p[i]--;
                y--;
                buff_y++;
            }
            y_heavy += p[i];
        }
    }

    if(x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }

    // now check if the less needed one can be satisfied with pairs
    if(x_heavy + y_heavy > x + y) {
        cout << "NO\n";
        // cout << "net based " << "\n";
        return;
    }

    if(y < x) {
        swap(x, y);
        swap(x_heavy, y_heavy);
        swap(x_req, y_req);
        swap(buff_x, buff_y);
    }

    // now x <= y for sure

    if(x * 2 < x_heavy) {
        cout << "NO\n";
        // cout << "bulk based " << "\n";
        return;
    }

    int rem_y = y - x - buff_x;

    if(rem_y > 0 && !y_req) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

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