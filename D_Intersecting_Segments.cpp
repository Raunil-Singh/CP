#include <bits/stdc++.h>
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

};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(2*n);
    segment_tree seg(v);
    for(int &num : v) { cin >> num; num--; }
    vector<int> pos(n , -1);
    for(int i = 0 ; i<2*n ; i++) {
        if(pos[v[i]] == -1) pos[v[i]] = i;
        else {
            int x = pos[v[i]];
            pos[v[i]] = (i - x - 1) - 2*seg.query(x, i);
            seg.update(x, 1);
        }
    }
    for(int num : pos) cout << num << " ";
    cout << "\n";
}