#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class segment_tree {

    int sze;
    vector<int> seg;

    int default_val;
    int rule(const int &a, const int &b) { return a+b; }

    int build(vector<int> &v, int curr, int l, int r) {
        if(l == r) return seg[curr] = v[l];
        int mid = (l+r)/2;
        return seg[curr] = rule(build(v, curr*2, l, mid), build(v, curr*2+1, mid+1, r));
    }

    int update_(int ind, int val, int curr, int l, int r) {
        if(ind < l || r < ind) return seg[curr];
        if(l == r) return seg[curr] = val;
        int mid = (l+r)/2;
        return seg[curr] = rule(update_(ind, val, curr*2, l, mid), update_(ind, val, curr*2+1, mid+1, r));
    }

    int query_(int l, int r, int curr, int L, int R) {
        if(r < L || R < l) return default_val;
        if(l <= L && R <= r) return seg[curr];
        int MID = (L+R)/2;
        return rule(query_(l, r, curr*2, L, MID), query_(l, r, curr*2+1, MID+1, R));
    }

public:

    segment_tree(vector<int>&v) : sze(v.size()), seg(4*v.size()), default_val(0) {
        build(v, 1, 0, sze-1);
    }

    int update(int ind, int val) {
        return update_(ind, val, 1, 0, sze-1);
    }

    int query(int l, int r) {
        return query_(l, r, 1, 0, sze-1);
    }

};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n); for(int &num : v) cin >> num;
    segment_tree seg(v);
 
    for(int i = 0 ; i<m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) seg.update(b, c);
        else cout << seg.query(b, c-1) << "\n";
    }

    return 0;

}