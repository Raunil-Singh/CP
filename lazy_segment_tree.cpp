class lazy_segment_tree {

    typedef struct data {
        static int query_default_val;
        int update;
        int query;
        data() : update(0), query(0) {}
        data(int u, int q) : update(u), query(q) {}
    } dt;

    int query_default_val, update_default_val;

    int sze;
    vector<dt> seg;
    
    /* update these if required */
    int query_op(int a, int b) { return a + b; }

    int update_op(int a, int b, int l, int r, int L, int R) { 
        return (b == update_default_val ? a : b * max((int)0, min(r,R)-max(l,L)+1));
    }

    void build(vector<int> &v, int curr, int l, int r) {
        if(l == r) {
            seg[curr] = data(update_default_val, v[l]);
            return;
        }
        int mid = (l+r)/2;
        build(v, curr*2, l, mid);
        build(v, curr*2 + 1, mid+1, r);
        seg[curr] = data(update_default_val, query_op(seg[curr*2].query, seg[curr*2+1].query));
    }

    void update(int l, int r, int v, int curr, int L, int R) {
        if(r < L || R < l) return;
        
        if(l <= L && R <= r) {
            seg[curr].update = update_op(seg[curr].update, v, 1, 1, 1, 1);
            seg[curr].query = update_op(seg[curr].query, v, L, R, L, R);
            return;
        }

        int mid = (L+R)/2;
        if(seg[curr].update != update_default_val) {
            update(L, R, seg[curr].update, curr*2, L, mid);
            update(L, R, seg[curr].update, curr*2+1, mid+1, R);
            seg[curr].update = update_default_val;
        }
        update(l, r, v, curr*2, L, mid);
        update(l, r, v, curr*2+1, mid+1, R);

        seg[curr].query = update_op(query_op(seg[curr*2].query, seg[curr*2+1].query), seg[curr].update, L, R, L, R);
    }

    int query(int l, int r, int curr, int L, int R) {
        if(r < L || R < l) return query_default_val;
        if(l <= L && R <= r) return seg[curr].query;
        int MID = (L+R)/2;
        return update_op(query_op(query(l, r, curr*2, L, MID), query(l, r, curr*2+1, MID+1, R)),
                        seg[curr].update, l, r, L, R);
    }

public:

    /* Update this if required */
    lazy_segment_tree(vector<int> &v) : seg(4 * v.size()), sze(v.size()),
                                        query_default_val(0),
                                        update_default_val(-1) {
        build(v, 1, 0, sze-1);
    }

    void update(int l, int r, int v) { update(l, r, v, 1, 0, sze-1); }
    int query(int l, int r) { return query(l, r, 1, 0, sze-1); }

    void print() {
        function <void(int, int, int)> dfs = [&](int curr, int l, int r) {
            cout << l << " - " << r << " : " << seg[curr].query << " , " << seg[curr].update << "\n";
            if(l==r) return;
            int mid = (l+r)/2;
            dfs(curr*2, l, mid);
            dfs(curr*2+1, mid+1, r);
        };
        dfs(1, 0, sze-1);
    }

};