#include <bits/stdc++.h>
using namespace std;

#define int int64_t

class segment_tree {

    int sze;
    vector<pair<int, int>> seg;

    pair<int, int> default_val;

    pair<int, int> rule(const pair<int, int> a, const pair<int, int> b) {
        if(a.first > b.first) return b;
        if(a.first < b.first) return a;
        else return make_pair(a.first, a.second + b.second);
    }

    pair<int, int> build(vector<int> &v, int curr, int l, int r) {
        if(l == r) seg[curr] = make_pair(v[l], 1);
        else {
            int mid = (l+r)/2;
            seg[curr] = rule(build(v, curr*2, l, mid), build(v, curr*2 + 1, mid+1, r));
        }
        return seg[curr];
    }

    pair<int, int> query_(int l, int r, int curr, int L, int R) {
        if(R < l || r < L) return default_val;
        if(l <= L && R <= r) return seg[curr];
        int MID = (L+R)/2;
        pair<int, int> result = rule(query_(l, r, curr*2, L, MID), query_(l, r, curr*2+1, MID+1, R));
        return result;
    }

    pair<int, int> update_(int x, int val, int curr, int L, int R) {
        if(x < L || x > R) return seg[curr];
        if(L == R) return seg[curr] = make_pair(val, 1);
        int MID = (L+R)/2;
        seg[curr] = rule(update_(x, val, curr*2, L, MID), update_(x, val, curr*2+1, MID+1, R));
        return seg[curr];
    }

public:

    segment_tree(vector<int> &v) : sze(v.size()), seg(4*v.size()), default_val(make_pair(INT_MAX, 1)) {
        build(v, 1, 0, sze-1);
    }
    
    /* @params l and r is 0 based */
    pair<int, int> query(int l, int r) {
        return query_(l, r, 1, 0, sze-1);
    }

    /* @params ind is 0 based */
    pair<int, int> update(int ind, int val) {
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
        else {
            auto x =seg.query(b, c-1);
            cout << x.first << " " << x.second << "\n";
        }
    }

}

