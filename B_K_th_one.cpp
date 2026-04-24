#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#define int int64_t

class segment_tree {

    typedef int dt; // update based on need

    int sze;
    vector<dt> seg;

    dt default_val;
    dt rule(const dt &a, const dt &b) { return a+b; } // Rule to find the value of a node based on children

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

    int result_(int k, int curr, int l, int r) {
        if(l==r) return l;
        if(seg[curr*2] < k) return result_(k - seg[curr*2], curr*2+1, (l+r)/2+1, r);
        else return result_(k, curr*2, l, (l+r)/2);
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

    void flip(int ind) {
        int curr = this->query(ind, ind);
        this->update(ind, 1-curr);
    }

    int result(int k) {
        return result_(k+1, 1, 0, sze-1);
    }

};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, m{};
    cin >> n >> m;
    vector<int> v(n); for(int &num : v) cin >> num;

    segment_tree seg(v);

    for(int i = 0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1) seg.flip(b);
        else cout << seg.result(b) << "\n";
    }

    return 0;
}