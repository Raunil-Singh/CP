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
#define MOD

inline void preprocessing() {

    // Code here

}

int query(int ind, int val) {
    cout << "? " << ind << " " << val << endl;
    int num; cin >> num;
    return num; 
}

void result(int x) {
    cout << "! " << x << endl;
}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    int present = n-1;
    int ans = 0;
    set<int> nums;
    for(int i = 1 ; i<=n ; i++) nums.insert(i);
    auto * given = new vector<int>(n);
    for(int i = 0 ; i<n ; i++) (*given)[i] = i+1;

    auto *eve = new vector<int>(n);
    auto *odd = new vector<int>(n);

    int bit = 1;
    while(present > 0) {
        int i0 = 0, i1 = 0;
        for(int i = 0 ; i<present ; i++) {
            int num = (*given)[i];
            if(query(num, bit)) {
                (*odd)[i1++] = num;
            } else {
                (*eve)[i0++] = num;
            }
        }
        int cnt[2] = {0,0};
        for(int i = 1 ; i<=n ; i++) {
            if((i&(bit-1)) == ans) cnt[(i&bit) > 0]++;
        }
        dbg(cnt, i0, i1);
        dbg(*eve, *odd);
        if(cnt[0] != i0) {
            dbg("Must be along 0 branch");
            swap(given, eve);
            present = i0;
        } else {
            dbg("Must be along 1 branch");
            swap(given, odd);
            present = i1;
            ans |= bit;
        }
        dbg(*given, present, ans);
        bit<<=1;
        while(((*nums.begin())&(bit-1)) != ans) nums.erase(*nums.begin());
        auto curr = nums.begin();
        auto next = curr; next++;
        while(next != nums.end()) {
            if(((*next)&(bit-1)) != ans) {
                nums.erase(*next);
                next = curr;
            } else {
                curr = next;
            }
            next++;
        }
    }

    result(*nums.begin());

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