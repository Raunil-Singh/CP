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



void solve(ll tc_no)
{
    ll n;
    cin >> n;
    vector<int> v(n);  inp(v);

    vector<int> sum(n);
    sum[0] = v[0];
    for(ll i = 1 ; i<n ; i++) sum[i] = sum[i-1] + v[i];

    vector<int> diff(n);
    diff[0] = 0;
    for(ll i = 1 ; i<n ; i++)
        diff[i] = diff[i-1] + (v[i]!=v[i-1]);
    
    auto unique = [&diff](int l, int r)->bool {
        if(l>r) return false;
        if(l == r) return true;
        return diff[r]>diff[l];
    };

    auto seg_sum = [&sum](int l, int r)->int {
        if(l==0) return sum[r];
        else return sum[r]-sum[l-1];
    };

    for(ll i = 0 ; i<n ; i++)
    {
        ll ans = INT_MAX;
        if((i>0 && seg_sum(0, i-1)>v[i]) && (unique(0, i-1) || v[i-1]>v[i]))
        {
            ll l = 0, r = i;
            while(l+1<r)
            {
                ll mid = (l+r)/2;
                if(seg_sum(mid, i-1)>v[i] && (unique(mid, i-1) || v[i-1]>v[i])) l = mid;
                else r = mid;
            }
            ans = min(ans, i-l);
        }
        if((i+1<n && seg_sum(i+1, n-1)>v[i]) && (unique(i+1, n-1) || v[i+1]>v[i]))
        {
            ll l = i, r = n-1;
            while(l+1<r)
            {
                ll mid = (l+r)/2;
                if(seg_sum(i+1, mid)>v[i] && (unique(i+1, mid) || v[i+1]>v[i])) r = mid;
                else l = mid;
            }
            ans = min(ans, r-i);
        }
        cout << (ans==INT_MAX ? -1 : ans) << " ";
    }

    cout << "\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}