#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class segment_tree {

    typedef vector<int> dt; // update based on need

    int sze;
    vector<dt> seg;

    dt default_val;
    dt rule(const dt &a, const dt &b) {
        int n = a.size(), m = b.size();
        dt v(n+m);
        int i = 0, j = 0;
        int pos = 0;
        while(pos < n+m) {
            if(i == n || (j<m && b[j] < a[i])) {
                v[pos] = b[j++];
            } else {
                v[pos] = a[i++];
            }
            pos++;
        }
        return v;
    } // Rule to find the value of a node based on children

    dt init_create(int num) { return {num}; } // Function to decide the info stored on nodes

    dt build(vector<int> &v, int curr, int l, int r) {
        if(l == r) return seg[curr] = init_create(v[l]);
        int mid = (l+r)/2;
        return seg[curr] = rule(build(v, curr*2, l, mid), build(v, curr*2+1, mid+1, r));
    }

    dt update_(int ind, dt val, int curr, int l, int r) {
        if(ind < l || r < ind) return seg[curr];
        if(l == r) return seg[curr] = val;
        int mid = (l+r)/2;
        return seg[curr] = rule(update_(ind, val, curr*2, l, mid), update_(ind, val, curr*2+1, mid+1, r));
    }

    dt query_(int l, int r, int curr, int L, int R) {
        if(r < L || R < l) return default_val;
        if(l <= L && R <= r) return seg[curr];
        int MID = (L+R)/2;
        return rule(query_(l, r, curr*2, L, MID), query_(l, r, curr*2+1, MID+1, R));
    }

    int get_ans_(int l, int r, int val, int curr, int L, int R) {
        if(r < L || R < l) return 0;
        if(l <= L && R <= r) return seg[curr].size() - (lower_bound(seg[curr].begin(), seg[curr].end(), (int)val) - seg[curr].begin());
        int mid = (L+R)/2;
        return get_ans_(l, r, val, curr*2, L, mid) + get_ans_(l, r, val, curr*2 + 1, mid+1, R);
    }

public:

    /* Update this based on requirements*/
    segment_tree(vector<int>&v) : sze(v.size()), seg(4*v.size()), default_val{} {
        build(v, 1, 0, sze-1);
    }

    // @params ind is 0-based
    dt update(int ind, int val) {
        dt valx = init_create(val);
        return update_(ind, valx, 1, 0, sze-1);
    }

    // @params l & r are 0-based
    dt query(int l, int r) {
        return query_(l, r, 1, 0, sze-1);
    }

    int get_ans(int l, int r, int val) {
        return get_ans_(l, r, val, 1, 0, sze-1);
    }

    void print_tree() {
        function<void(int, int, int)> dfs = [&](int curr, int l, int r) {
            cout << l << " " << r << " -> ";
            for(int num : seg[curr]) cout << num << " ";
            cout << "\n";
            int mid = (l+r)/2;
            if(l == r) return;
            dfs(curr*2, l, mid);
            dfs(curr*2 + 1, mid+1, r);
        };
        dfs(1, 0, sze-1);
    }

};

int32_t main() {

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &num : v) cin >> num;
    segment_tree seg(v);

    // cout << "Built!\n";

    // seg.print_tree();

    int q; cin >> q;
    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << seg.get_ans(i-1, j-1, k+1) << "\n";
    }

    return 0;
}