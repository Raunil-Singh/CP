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

class lazy_segment_tree {

    typedef struct data {
        int inc;
        int min;

        data() : inc(0), min(INT_MAX) {}
        data(int x) : inc(0), min(x) {}

    } dt;

    int sze;
    vector<dt> seg;

    dt init_create(int x) { return data(x); }

    void build(vector<int> &v, int curr, int l, int r) {
        if(l == r) {
            seg[curr] = init_create(v[l]);
            return;
        }
        int mid = (l+r)/2;
        build(v, curr*2, l, mid);
        build(v, curr*2 + 1, mid + 1, r);
        seg[curr] = init_create(min(seg[curr*2].min, seg[curr*2 + 1].min));
    }

    void increment(int l, int r, int val, int curr, int L, int R) {
        if(R < l || r < L) return;
        if(l <= L && R <= r) {
            seg[curr].inc += val;
            seg[curr].min += val;
            return;
        }
        int mid = (L+R)/2;
        increment(l, r, val, curr*2, L, mid);
        increment(l, r, val, curr*2+1, mid+1, R);
        seg[curr].min = min(seg[curr*2].min, seg[curr*2+1].min) + seg[curr].inc;
    }

    int get_(int l, int r, int curr, int L, int R) {
        if(r < L || R < l) return ((int)INT_MAX) * 4;
        if(l <= L && R <= r) return seg[curr].min;
        int mid = (L+R)/2;
        return seg[curr].inc + min(get_(l, r, curr*2, L, mid), get_(l, r, curr*2+1, mid+1, R));
    }

    

public:

    lazy_segment_tree(vector<int> &v) : seg(4*v.size()), sze(v.size()) { build(v, 1, 0, sze-1); }

    void inc(int l, int r, int val) { increment(l, r, val, 1, 0, sze-1); }

    int get(int l, int r) { return get_(l, r, 1, 0, sze-1); }

    void print() {
        function <void(int, int, int)> dfs = [&](int curr, int l, int r) {
            cout << l << " - " << r << " : " << seg[curr].min << " , " << seg[curr].inc << "\n";
            if(l==r) return;
            int mid = (l+r)/2;
            dfs(curr*2, l, mid);
            dfs(curr*2+1, mid+1, r);
        };
        dfs(1, 0, sze-1);
    }

};

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ":\n";
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    lazy_segment_tree seg(v);

    while(q--) {
        int choice; cin >> choice;
        if(choice == 1) {
            int l, r, v; cin >> l >> r >> v;
            seg.inc(l, r-1, v);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.get(l, r-1) << "\n";
        }
        // seg.print();
        // cout << "-----------\n";
    }
}

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
    // cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}