#include <bits/stdc++.h>
using namespace std;

#define int int64_t

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

    int compute_(int x, int l, int curr, int L, int R) {
        // cout << curr << " " << L << " " << R << " ##\n";
        if(L == R) return (seg[curr] >= x ? L : -1);
        int mid = (L+R)/2;
        int res = -1;
        if(l <= mid && seg[curr*2] >= x) res = compute_(x, l, curr*2, L, mid);
        if(res == -1 && seg[curr*2+1] >= x) res = compute_(x, l, curr*2+1, mid+1, R);
        return res;
    }

public:

    /* Update this based on requirements*/
    segment_tree(vector<int>&v) : sze(v.size()), seg(4*v.size()), default_val(0) {
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

    int compute(int x, int l) {
        int res = compute_(x, l, 1, 0, sze-1);
        return res;
    }

};

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n); for(int &num : v) cin >> num;

    segment_tree seg(v);

    for(int i = 0 ; i<m ; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int ind, x;
            cin >> ind >> x;
            seg.update(ind, x);
        } else {
            int x, l;
            cin >> x >> l;
            cout << seg.compute(x, l) << "\n";
        }
    }

}