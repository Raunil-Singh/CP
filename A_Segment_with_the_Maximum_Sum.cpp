#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class segment_tree {

    typedef struct{
        int lb, b, rb, s;
    } dt; // update based on need
    /* left_best, best, right_best, sum */

    int sze;
    vector<dt> seg;

    dt default_val;
    dt rule(const dt &a, const dt &b) {
        return {
            max(a.lb, a.s + b.lb),
            max(max(a.b, b.b), a.rb + b.lb),
            max(b.rb, b.s + a.rb),
            a.s + b.s};
    }
    
    dt init_create(int num) {
        return {max(num, int(0)), max(num, int(0)), max(num, int(0)), num};
    }

    dt build(vector<int> &v, int curr, int l, int r) {
        if(l == r) return seg[curr] = init_create(v[l]);
        int mid = (l+r)/2;
        return seg[curr] = rule(build(v, curr*2, l, mid), build(v, curr*2+1, mid+1, r));
    }

    dt update_(int ind, int val, int curr, int l, int r) {
        if(ind < l || r < ind) return seg[curr];
        if(l == r) return seg[curr] = init_create(val);
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
    segment_tree(vector<int>&v) : sze(v.size()), seg(4*v.size()), default_val() {
        build(v, 1, 0, sze-1);
    }

    // @params ind is 0-based
    dt update(int ind, int val) {
        return update_(ind, val, 1, 0, sze-1);
    }

    // @params l & r are 0-based
    int query(int l, int r) {
        return query_(l, r, 1, 0, sze-1).b;
    }

};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n); for(int &num : v) cin >> num;
    segment_tree seg(v);

    cout << seg.query(0, n-1) << "\n";

    for(int i = 0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        seg.update(a, b);
        cout << seg.query(0, n-1) << "\n";
    }
 
    return 0;

}