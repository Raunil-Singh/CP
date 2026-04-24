#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class segment_tree {

    typedef int dt; // update based on need

    int sze;
    vector<dt> seg;

    dt default_val;
    dt rule(const dt &a, const dt &b) { return min(a, b); } // Rule to find the value of a node based on children

    dt init_create(int num) { return num; } // Function to decide the info stored on nodes

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

    dt compute_(int l, int r, int p, int curr, int L, int R) {
        if(r < L || R < l) return 0;
        if(seg[curr] > p) return 0;

        if(L == R) {
            seg[curr] = INT_MAX;
            return 1;
        }

        int mid = (L+R)/2;
        int ans = compute_(l, r, p, curr*2, L, mid) + compute_(l, r, p, curr*2 + 1, mid+1, R);

        seg[curr] = rule(seg[curr*2], seg[curr*2+1]);

        return ans;
    }

public:

    /* Update this based on requirements*/
    segment_tree(vector<int>&v) : sze(v.size()), seg(4*v.size()), default_val(INT_MAX) {
        build(v, 1, 0, sze-1);
    }

    // @params ind is 0-based
    dt update(int ind, int val) {
        return update_(ind, val, 1, 0, sze-1);
    }

    // @params l & r are 0-based
    dt query(int l, int r) {
        return query_(l, r, 1, 0, sze-1);
    }

    int compute(int l, int r, int p) {
        return compute_(l, r, p, 1, 0, sze-1);
    }

};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> health(n, INT_MAX);
    segment_tree seg(health);

    for(int _ = 0 ; _<m ; _++) {
        int type; cin >> type;
        if(type == 1) {
            int i, h;
            cin >> i >> h;
            seg.update(i, h);
        } else {
            int l, r, p; cin >> l >> r >> p;
            cout << seg.compute(l, r-1, p) << "\n";
        }
    }

    return 0;
}