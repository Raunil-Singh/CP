#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <queue>
#include <utility>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#else
#define dbg(x) ;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n); inp(a); inp(b);

    int del = 0;
    int ans = (m)*(m+1)/2;
    int lc = 1;
    int cnt = 1;

    for(int i = 0 ; i<n ; i++) {
        dbg("Start of iteration");
        dbg(i);
        dbg(ans);
        dbg()
        int del_count = 0;
        del += b[i];
        int new_min = max(lc+del, a[i]);
        dbg(lc);
        dbg(cnt);
        dbg(new_min);
        if(del + lc <= new_min) {
            dbg("In block1");
            del_count += cnt;
            ans -= lc * cnt;
            dbg(del_count);
            dbg(ans);
        }
        if(m!=cnt && lc + 1 + del <= new_min) {
            dbg("In Block2");
            int up = min(m, new_min - del);
            int low = lc + 1;
            ans -= up*(up+1)/2 - low*(low-1)/2;
            del_count += up - low + 1;
            dbg(up);
            dbg(low);
            dbg(ans);
            dbg(del_count);
        }
        dbg("Update Phase");
        lc = new_min - del;
        dbg(lc);
        ans += (lc) * del_count;
        if(del_count > 0) cnt = del_count;
    }

    ans += del * m;
    cout << ans << "\n";


}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    
    
****/

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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