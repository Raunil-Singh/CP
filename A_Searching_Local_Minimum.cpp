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

constexpr int64_t inf = 1'000'000'000;

int get(int i) {
    cout << "? " << i+1 << endl;
    int x; cin >> x;
    return x;
}

void res(int x) {
    cout << "! " << x+1 << endl;
}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> arr(n, inf);

    int l = 0, r = n-1;

    while(l+1<r) {
        if(arr[l] == inf) arr[l] = get(l);
        if(arr[r] == inf) arr[r] = get(r);

        dbg("init_query");

        int mid = (l+r)/2;

        if(arr[mid] == inf) arr[mid] = get(mid);

        if(arr[mid] < max(arr[l], arr[r]) && arr[mid] > min(arr[l], arr[r])) {
            dbg("Case 1");
            if(arr[l] > arr[r]) l = mid;
            else r = mid;
        }
        else if(arr[mid] < min(arr[l], arr[r])) {
            dbg("Case 2");
            if(arr[mid+1] == inf) arr[mid+1] = get(mid+1);
            if(arr[mid] < arr[mid+1]) r = mid;
            else l = mid+1;
        }
        else if(arr[l] < arr[r]) { r = mid; dbg("Case 3"); }
        else { l = mid; dbg("Case 4"); }   
        dbg(l, r);
    }

    dbg(l, r);

    if(arr[l] == inf) arr[l] = get(l);
    if(arr[r] == inf) arr[r] = get(r);

    dbg("Result pending!");

    if(arr[l] < arr[r]) res(l);
    else res(r);

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