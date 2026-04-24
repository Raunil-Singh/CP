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

int c1[150][150], c2[150][150];

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;

    for(int i = 0 ; i<n ; i++) {
        for(int j = 0 ; j<n ; j++) {
            c1[i][j] = INT_MAX;
            c2[i][j] = INT_MAX;
        }
    }

    for(int i = 0 ; i<n ; i++) {
        for(int j = i ; j<n ; j++) {
            int x; cin >> x;
            if(x == 1) {
                c2[i][j] = 0;
            } else if(x == 2) {
                c1[i][j] = 0;
            }
        }
    }

    for(int i = n-1 ; i>=0 ; i--) {
        for(int j = 0 ; j<i ; j++) {
            if(c2[i][j] != 0) continue;
            if(c1[i][j-1] == 0 || c1[i+1][j] == 0) {
                cout << "0\n";
                return;
            }
            c2[i][j-1] = min(c2[i][j-1], c2[i][j]);
            c2[i+1][j] = min(c2[i+1][j], c2[i][j]);
        }
    }

    for(int i = 0 ; i<n ; i++) {
        c1[i][i] = min((int)1, c1[i][i]);
        c2[i][i] = 0;    
    }

    for(int i = n-1 ; i>=0 ; i--) {
        for(int j = i+1 ; j<n ; j++) {
            c1[i][j] = min(min(c1[i][j-1], c1[i+1][j]), c1[i][j]);
        }
    }

    for(int i = n-1 ; i>=0 ; i--) {
        for(int j = i+1 ; j<n ; j++) {
            if(c2[i][j] == 0) continue;
            c2[i][j] = 0;
            for(int k = i ; k<j ; k++) {
                c2[i][j] = (c2[i][j] + c1[i][k]*(c1[k+1][j] + c2[k+1][j])*(j == i+1 ? 1 : (c2[k][k+1]>0))) % MOD;
            }
        }
    }

    // for(int i = 0 ; i<n ; i++) {
    //     for(int j = 0 ; j<n ; j++) {
    //         cout << (c1[i][j]==INT_MAX ? "--" : to_string(c1[i][j])) << "\t";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    // for(int i = 0 ; i<n ; i++) {
    //     for(int j = 0 ; j<n ; j++) {
    //         cout << (c2[i][j]==INT_MAX ? "--" : to_string(c2[i][j])) << "\t";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";

    cout << ((c1[0][n-1] + c2[0][n-1])<<1) % MOD << "\n";

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