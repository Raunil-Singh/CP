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

class segment_tree {

    typedef int dt; // update based on need

    int sze;
    vector<dt> seg;

    dt default_val;
    dt rule(const dt &a, const dt &b) { return max(a, b); } // Rule to find the value of a node based on children

    dt init_create(int num) { return num; } // Function to decide the info stored on nodes

    dt build(vector<int> &v, int curr, int l, int r) {
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
    segment_tree(vector<int>&v) : sze(v.size()), seg(4*v.size()), default_val(INT_MIN) {
        build(v, 1, 0, sze-1);
    }

    // @params ind is 0-based
    dt update(int ind, int val) {
        dt valx = init_create(val);
        return update_(ind, valx, 1, 0, sze-1);
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

    vector<int> v(n), prev(n); inp(v);
    map<int, set<int>> mpp;
    for(int i = 0 ; i<n ; i++) {
        prev[i] = (mpp.find(v[i]) == mpp.end()) ? -1 : *mpp[v[i]].rbegin();
        mpp[v[i]].insert(i);
    }

    segment_tree seg(prev);

    while(q--) {
        int i, a, b; cin >> i >> a >> b;
        if(i == 1) {
            a--;
            // handle the place where deleting from
            int num = v[a];
            int p = prev[a];
            mpp[num].erase(a);
            if(mpp[num].lower_bound(a) != mpp[num].end()) {
                int next = *mpp[num].lower_bound(a);
                prev[next] = p;
                seg.update(next, p);
            }
            // handle the new insert
            num = v[a] = b;
            if(mpp[num].lower_bound(a) != mpp[num].end()) {
                int next = *mpp[num].lower_bound(a);
                mpp[num].insert(a);
                prev[a] = prev[next];
                prev[next] = a;
                seg.update(next, prev[next]);
                seg.update(a, prev[a]);
            } else {
                if(mpp[num].size() == 0) {
                    mpp[num].insert(a);
                    prev[a] = -1;
                    seg.update(a, -1);
                } else {
                    auto p = *(--mpp[num].lower_bound(a));
                    mpp[num].insert(a);
                    prev[a] = p;
                    seg.update(a, p);
                }
            }

        } else {
            cout << (seg.query(a-1, b-1) < a-1 ? "YES\n" : "NO\n");
        }
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