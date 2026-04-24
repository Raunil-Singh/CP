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

    typedef struct query_node {
        int seg, pref, suff, sum;
        query_node() : seg(0), pref(0), suff(0), sum(0) {}
        query_node(int x) {
            seg = pref = suff = max((int)0, x);
            sum = x;
        }
    } qn;

    typedef struct data {
        int update;
        qn query;
        data() : update(0), query() {}
        data(int u, int q) : update(u), query(q) {}
        data(int u, qn q) : update(u), query(q) {}
    } dt;

    int query_default_val, update_default_val;

    int sze;
    vector<dt> seg;
    
    /* update these if required */
    qn query_op(qn a, qn b) { 
        qn res;
        res.seg = max(max(a.seg, b.seg), a.suff + b.pref);
        res.pref = max(a.pref, a.sum + b.pref);
        res.suff = max(a.suff + b.sum, b.suff);
        res.sum = a.sum + b.sum;
        return res;
    }

    int update_op(int a, int b, int l, int r, int L, int R) { 
        return (b == update_default_val ? a : b * max((int)0, min(r,R)-max(l,L)+1));
    }

    void build(vector<int> &v, int curr, int l, int r) {
        if(l == r) {
            seg[curr] = data(update_default_val, v[l]);
            return;
        }
        int mid = (l+r)/2;
        build(v, curr*2, l, mid);
        build(v, curr*2 + 1, mid+1, r);
        seg[curr] = data(update_default_val, query_op(seg[curr*2].query, seg[curr*2+1].query));
    }

    void update(int l, int r, int v, int curr, int L, int R) {
        if(r < L || R < l) return;
        
        if(l <= L && R <= r) {
            seg[curr].update = update_op(seg[curr].update, v, 1, 1, 1, 1);
            seg[curr].query = update_op(seg[curr].query, v, L, R, L, R);
            return;
        }

        int mid = (L+R)/2;
        if(seg[curr].update != update_default_val) {
            update(L, R, seg[curr].update, curr*2, L, mid);
            update(L, R, seg[curr].update, curr*2+1, mid+1, R);
            seg[curr].update = update_default_val;
        }
        update(l, r, v, curr*2, L, mid);
        update(l, r, v, curr*2+1, mid+1, R);

        seg[curr].query = update_op(query_op(seg[curr*2].query, seg[curr*2+1].query), seg[curr].update, L, R, L, R);
    }

    qn query(int l, int r, int curr, int L, int R) {
        if(r < L || R < l) return query_default_val;
        if(l <= L && R <= r) return seg[curr].query;
        int MID = (L+R)/2;
        return update_op(query_op(query(l, r, curr*2, L, MID), query(l, r, curr*2+1, MID+1, R)),
                        seg[curr].update, l, r, L, R);
    }

public:

    /* Update this if required */
    lazy_segment_tree(vector<int> &v) : seg(4 * v.size()), sze(v.size()),
                                        query_default_val(0),
                                        update_default_val(INT_MAX) {
        build(v, 1, 0, sze-1);
    }

    void update(int l, int r, int v) { update(l, r, v, 1, 0, sze-1); }
    int query(int l, int r) { return query(l, r, 1, 0, sze-1); }

    void print() {
        function <void(int, int, int)> dfs = [&](int curr, int l, int r) {
            cout << l << " - " << r << " : " << seg[curr].query << " , " << seg[curr].update << "\n";
            if(l==r) return;
            int mid = (l+r)/2;
            dfs(curr*2, l, mid);
            dfs(curr*2+1, mid+1, r);
        };
        dfs(1, 0, sze-1);
    }

};

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    
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
    cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}