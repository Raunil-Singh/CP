#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

#define int int64_t

class lazy_segment_tree {

    int sze;
    vector<int> seg;

    void build(vector<int> &v, int curr, int l, int r) {
        if(l == r) {
            seg[curr] = v[l];
            return;
        }
        int mid = (l+r)/2;
        seg[curr] = 0;
        build(v, curr*2, l, mid);
        build(v, curr*2 + 1, mid + 1, r);
    }

    void increment(int l, int r, int val, int curr, int L, int R) {
        if(R < l || r < L) return;
        if(l <= L && R <= r) {
            seg[curr] += val;
            return;
        }
        int mid = (L+R)/2;
        increment(l, r, val, curr*2, L, mid);
        increment(l, r, val, curr*2+1, mid+1, R);
    }

    int get_(int ind, int curr, int l, int r) {
        if(ind < l || ind > r) return 0;
        if(l == r) return seg[curr];
        int mid = (l+r)/2;
        return seg[curr] + get_(ind, curr*2, l, mid) + get_(ind, curr*2+1, mid+1, r);
    }

public:

    lazy_segment_tree(vector<int> &v) : seg(4*v.size()), sze(v.size()) { build(v, 1, 0, sze-1); }

    void inc(int l, int r, int val) { increment(l, r, val, 1, 0, sze-1); }

    int get(int ind) { return get_(ind, 1, 0, sze-1); }

    void print(int curr, int l, int r) {
        cout << l << " - " << r << " : " << seg[curr] << "\n";
        if(l == r) return;
        int mid = (l+r)/2;
        print(curr*2, l, mid);
        print(curr*2 + 1, mid+1, r);
    }

};

int32_t main() {

    int n, q;
    cin >> n >> q;

    vector<int> v(n); for(int &num : v) cin >> num;
    lazy_segment_tree lseg(v);

    while(q--) {
        // lseg.print(1, 0, n-1);
        int t; cin >> t;
        if(t == 1) {
            int a, b, u; cin >> a >> b >> u; a--; b--;
            lseg.inc(a, b, u);
        } else {
            int k; cin >> k; cout << lseg.get(k-1) << "\n"; 
        }
    }

    return 0;
}