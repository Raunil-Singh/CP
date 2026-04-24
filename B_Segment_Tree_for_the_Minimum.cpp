#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class segment_tree {

    int sze;
    vector<int> seg;

    int default_val = INT_MAX;

    int rule(const int a, const int b) { return min(a, b); }

    int build(vector<int> &v, int curr, int l, int r) {
        if(l == r) seg[curr] = v[l];
        else {
            int mid = (l+r)/2;
            seg[curr] = rule(build(v, curr*2, l, mid), build(v, curr*2 + 1, mid+1, r));
        }
        return seg[curr];
    }

    int query_(int l, int r, int curr, int L, int R) {
        if(l <= L && R <= r) return seg[curr];
        int MID = (L+R)/2;
        int result = rule(query_(l, r, curr*2, L, MID), query_(l, r, curr*2+1, MID+1, R));
        return result;
    }

    int update_(int x, int val, int curr, int L, int R) {
        if(x < L || x > R) return seg[curr];
        if(L == R) return seg[curr] = val;
        int MID = (L+R)/2;
        seg[curr] = rule(update_(x, val, curr*2, L, MID), update_(x, val, curr*2+1, MID+1, R));
        return seg[curr];
    }

public:

    segment_tree(vector<int> &v) : sze(v.size()), seg(4*v.size()) {
        build(v, 1, 0, sze-1);
    }
    
    /* @params l and r is 0 based */
    int query(int l, int r) {
        return query_(l, r, 1, 0, sze-1);
    }

    /* @params ind is 0 based */
    int update(int ind, int val) {
        return update_(ind, val, 1, 0, sze-1);
    }

};



int32_t main() {
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

}

