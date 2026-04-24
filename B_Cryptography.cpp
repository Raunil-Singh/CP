#include <bits/stdc++.h>
using namespace std;

#define int int64_t

struct matrix {
    int a, b, c, d;
};

class segment_tree {

    typedef matrix dt; // update based on need

    int r;
    int sze;
    vector<dt> seg;

    dt default_val;
    dt rule(const dt &a, const dt &b) {
        return {
            (a.a*b.a + a.b*b.c) % r,
            (a.a*b.b + a.b*b.d) % r,
            (a.c*b.a + a.d*b.c) % r,
            (a.c*b.b + a.d*b.d) % r
        };
    } // Rule to find the value of a node based on children

    dt init_create(dt num) { return {num.a%r, num.b%r, num.c%r, num.d%r}; } // Function to decide the info stored on nodes

    dt build(vector<dt> &v, int curr, int l, int r) {
        if(l == r) return seg[curr] = init_create(v[l]);
        int mid = (l+r)/2;
        return seg[curr] = rule(build(v, curr*2, l, mid), build(v, curr*2+1, mid+1, r));
    }

    dt update_(int ind, dt val, int curr, int l, int r) {
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
    segment_tree(vector<dt>&v, int mod) : sze(v.size()), seg(4*v.size()), default_val{1,0,0,1}, r(mod) {
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

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, n, m;
    cin >> r >> n >> m;

    vector<matrix> v(n); for(auto &x : v) cin >> x.a >> x.b >> x.c >> x.d;

    segment_tree seg(v, r);

    while(m--) {
        int i, j;
        cin >> i >> j;
        matrix res = seg.query(i-1, j-1);
        cout << res.a << " " << res.b << "\n" << res.c << " " << res.d << "\n";
        cout << "\n";
    }

    return 0;
}