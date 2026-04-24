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

struct node {
    int sum, total, count_max;
    node() {
        sum = 0;
        total = 0;
        count_max = 0;
    }
    node(int a, int b, int c) : sum(a), total(b), count_max(c) {};
};

class segment_tree {

    typedef node dt; // update based on need

    int sze;
    vector<dt> seg;

    dt default_val;
    dt rule(const dt &a, const dt &b) {
        return {a.sum + b.sum, a.total + b.total, b.count_max};
    } // Rule to find the value of a node based on children

    dt init_create(int num) { return node(); } // Function to decide the info stored on nodes

    dt build(const vector<int> &v, int curr, int l, int r) {
        if(l == r) return seg[curr] = init_create(v[l]);
        int mid = (l+r)/2;
        return seg[curr] = rule(build(v, curr*2, l, mid), build(v, curr*2+1, mid+1, r));
    }

    dt update_(int ind, dt val, int curr, int l, int r) {
        if(ind < l || r < ind) return seg[curr];
        if(l == r) return seg[curr] = val;
        int mid = (l+r)/2;
        return seg[curr] = rule(update_(ind, val, curr*2, l, mid), update_(ind, val, curr*2+1, mid+1, r));
    }

    dt query_(int l, int r, int curr, int L, int R) {
        if(r < L || R < l) return default_val;
        if(l <= L && R <= r) return seg[curr];
        int MID = (L+R)/2;
        return rule(query_(l, r, curr*2, L, MID), query_(l, r, curr*2+1, MID+1, R));
    }

public:

    /* Update this based on requirements*/
    segment_tree(const vector<int>&v) : sze(v.size()), seg(4*v.size()), default_val() {
        build(v, 1, 0, sze-1);
    }

    // @params ind is 0-based
    dt update(int ind, dt val) {
        return update_(ind, val, 1, 0, sze-1);
    }

    // @params l & r are 0-based
    dt query(int l, int r) {
        return query_(l, r, 1, 0, sze-1);
    }

};

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, q;
    cin >> n >> q;
    vector<int> v(n); inp(v);

    segment_tree seg(vector<int>(n+1));

    map<pair<int, int>, vector<int>> idx;
    for(int i = 0 ; i<q ; i++) {
        int x, y;
        cin >> x >> y;
        idx[{x, y}].push_back(i);
    }

    vector<int> res(q);

    int to_insert = 0;
    for(auto [pair, vec] : idx) {
        auto [x, y] = pair;
        while(to_insert < x) {
            auto curr = seg.query(to_insert, to_insert);
            curr.count_max++;
            curr.total++;
            curr.sum += v[to_insert];

            seg.update(to_insert, curr);
            to_insert++;
        }
        int l = 0, r = n+1;
        while(l+1 < r) {
            int mid = (l+r)/2;
            if(check(mid)) l = mid;
            else r = mid; 
        }
        auto curr = seg.query(0, l);
        int fixed = curr.sum - curr.count_max * l;
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