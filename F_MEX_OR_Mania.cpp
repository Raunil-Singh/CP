// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]

template <typename T>
class seg_tree
{
private:
    vector<T> seg;
    int size;

    T property(T val1, T val2)
    {
        return (val1|val2); // Edit the seg_tree property here
    }

    void _build(const vector<T> &v, int node, int l, int r)
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
            return 0; // Edit this neutral value if needed

        if (l <= cl && cr <= r)
            return seg[node];

        int cm = (cl + cr) / 2;

        return property(_query(2 * node + 1, l, r, cl, cm),
                        _query(2 * node + 2, l, r, cm + 1, cr));
    }

public:
    void build(const vector<T> &v)
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

void solve(ll tc_no)
{
    
    // code here
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}