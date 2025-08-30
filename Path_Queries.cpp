// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void dfs(int par, int curr, vector<vector<int>> &adj, vector<int> &seq)
{
    seq.pb(curr);
    for(int next : adj[curr])
    {
        if(next == par) continue;
        dfs(curr, next, adj, seq);
    }
    seq.pb(curr);
}

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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, q;
    cin >> n >> q;
    vector<int> v(n); inp(v);

    vector<vector<int>> adj(n);
    for(int i = 1 ; i<n ; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> seq;
    dfs(-1, 0, adj, seq);

    map<int, vector<int>> m;
    for(int i = 0 ; i<(n<<1) ; i++)
    {
        m[seq[i]].pb(i);
    }

    for(int i = 0 ; i<n ; i++)
    {
        seq[m[i][0]] = v[i];
        seq[m[i][1]] = -v[i];
    }

    seg_tree <int> seg([](const int &a, const int &b) -> int {return a+b;}, 0LL); 
    seg.build(seq);

    for(int i = 0 ; i<q ; i++)
    {
        int choice, s;
        cin >> choice >> s;
        s--;
        if(choice == 1)
        {
            int x;
            cin >> x;
            seg.update(m[s][0], x);
            seg.update(m[s][1], -x);
        }
        else cout << seg.query(0, m[s][0]) << "\n";
    }
    
    return 0;
}