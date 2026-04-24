#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class lazy_segment_tree {

    typedef int dt;

    int sze;
    vector<dt> seg;

    bool associative;

    dt default_val;

    dt rule(const dt &a, const dt &b) { return a+b; }

    dt init_create(int x) { return x; }

    void build(vector<int> &v, int curr, int l, int r) {
        if(l == r) seg[curr] = init_create(v[l]);
        else {
            int mid = (l+r)/2;
            build(v, curr*2, l, mid);
            build(v, curr*2 + 1, mid+1, r);
        }
    }

    void range_update_(int l, int r, dt &val, int curr, int L, int R) {
        if(r < L || R < l) return; // no overlap
        if(L == R) { seg[curr] = rule(seg[curr], val); return; } // overlap leaf
        
        // Exact match
        if(l == L && R == r) {
            seg[curr] = rule(seg[curr], val);
            return;
        }

        int MID = (L+R)/2;
        
        // Partial match
        if(!associative && seg[curr] != default_val) {
            range_update_(L, MID, seg[curr], curr*2, L, MID);
            range_update_(MID+1, R, seg[curr], curr*2+1, MID+1, R);
            seg[curr] = default_val;
        }

        if(l <= L && R <= r) {
            seg[curr] = rule(seg[curr], val);
            return;
        }

        range_update_(l, r, val, curr*2, L, MID);
        range_update_(l, r, val, curr*2+1, MID+1, R);
    }

    int get_leaf_(int ind, int curr, int l, int r) {
        if(l == r) return curr;
        int mid = (l+r)/2;
        if(ind <= mid) return get_leaf_(ind, curr*2, l, mid);
        else return get_leaf_(ind, curr*2+1, mid+1, r);
    }

    dt point_query_(int ind) {
        int node = get_leaf_(ind, 1, 0, sze-1);
        dt val = seg[node]; node/=2;
        while(node > 0) {
            val = rule(val, seg[node]);
            node/=2;
        }
        return val;
    }

    void print_seg_tree_(int curr, int l, int r) {
        cout << l << " - " << r << " : " << seg[curr] << "\n";
        if(l==r) return;
        int mid = (l+r)/2;
        print_seg_tree_(curr*2, l, mid);
        print_seg_tree_(curr*2+1, mid+1, r);
    }

public:

    lazy_segment_tree(vector<int> &v, bool associativity_of_rule) : 
        sze(v.size()), associative(associativity_of_rule), default_val(0) {
        seg.assign(4*sze, default_val);
        build(v, 1, 0, sze-1);
    }

    // @params l and r are 0-based
    void range_update(int l, int r, int val) { 
        dt valx = init_create(val);
        range_update_(l, r, valx, 1, 0, sze-1);
    }

    // @params ind is 0-based
    dt get(int ind) { return point_query_(ind); }

    void print_seg_tree(int x) {
        cout << "Tree config : ----- "<< x << " -----\n";
        print_seg_tree_(1, 0, sze-1);
        cout << "--------------------------\n";
    }

};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, m{};
    cin >> n >> m;

    vector<int> v(n);
    lazy_segment_tree lseg(v, true);

    while(m--) {
        int t; cin >> t;
        if(t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            lseg.range_update(l, r-1, v);
            // lseg.print_seg_tree(m);
        } else {
            int i;
            cin >> i;
            cout << lseg.get(i) << "\n";
        }
    }

    return 0;
}