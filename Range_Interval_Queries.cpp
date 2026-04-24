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

class merge_sort_tree {
    vector<vector<int>> seg;
    int sze;
    void build(vector<int> &v, int curr, int l, int r) {
        if(l == r) {
            seg[curr].push_back(v[l]);
            return;
        }
        int mid = (l+r)>>1;
        build(v, curr*2, l, mid);
        build(v, curr*2 + 1, mid+1, r);
        auto &a = seg[curr*2], &b = seg[curr*2+1];
        int i = 0, j = 0;
        seg[curr].reserve(a.size() + b.size());
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) seg[curr].push_back(a[i++]);
            else seg[curr].push_back(b[j++]);
        }
        while(i < a.size()) seg[curr].push_back(a[i++]);
        while(j < b.size()) seg[curr].push_back(b[j++]);
    }
    int query_leq(int curr, int l, int r, int lx, int rx, int x) {
        if(rx < l || r < lx) return 0;
        if(lx<=l && r<=rx) {
            return upper_bound(all(seg[curr]), x) - seg[curr].begin();
        }
        int mid = (l+r)/2;
        return query_leq(curr*2, l, mid, lx, rx, x) + query_leq(curr*2+1, mid+1, r, lx, rx, x);
    }
public:
    merge_sort_tree(vector<int> &v) : seg(4*v.size()), sze(v.size()) {
        build(v, 1, 0, sze-1);
    }

    int range_query(int l, int r, int lo, int hi) {
        int a = query_leq(1, 0, sze-1, l, r, hi);
        int b = query_leq(1, 0, sze-1, l, r, lo-1);
        return a-b;
    }
};

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, q;
    cin >> n >> q;
    vector<int> v(n); inp(v);

    merge_sort_tree mst(v);

    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << mst.range_query(a-1, b-1, c, d) << "\n";
    }

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