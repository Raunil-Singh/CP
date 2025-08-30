template <typename T>
class seg_tree
{
private:
    std::vector<T> seg;
    int size;
    std::function<T(T, T)> property;
    T neutral;

    void _build(const std::vector<T> &v, int node, int l, int r)
    {
        if (l == r)
        {
            seg[node] = v[l];
            return;
        }

        int mid = (l + r) / 2;
        _build(v, 2 * node + 1, l, mid);
        _build(v, 2 * node + 2, mid + 1, r);

        seg[node] = property(seg[2 * node + 1], seg[2 * node + 2]);
    }

    void _update(int node, int l, int r, int ind, T val)
    {
        if (l == r)
        {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (ind <= mid)
            _update(2 * node + 1, l, mid, ind, val);
        else
            _update(2 * node + 2, mid + 1, r, ind, val);

        seg[node] = property(seg[2 * node + 1], seg[2 * node + 2]);
    }

    T _query(int node, int l, int r, int cl, int cr)
    {
        if (cr < l || cl > r)
            return neutral;

        if (l <= cl && cr <= r)
            return seg[node];

        int cm = (cl + cr) / 2;
        return property(_query(2 * node + 1, l, r, cl, cm),
                        _query(2 * node + 2, l, r, cm + 1, cr));
    }

public:
    seg_tree(std::function<T(T, T)> op, T neutral_value)
        : property(op), neutral(neutral_value) {}

    void build(const std::vector<T> &v)
    {
        size = v.size();
        seg.resize(4 * size);
        _build(v, 0, 0, size - 1);
    }

    void update(int index, T val)
    {
        _update(0, 0, size - 1, index, val);
    }

    T query(int l, int r)
    {
        return _query(0, l, r, 0, size - 1);
    }
};
// seg_tree<type> name(comparator, neutral_val ---> returned when invalid segment...generally 0)