// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void preprocessing()
{

    // Code here

}

int merge_sort(vector<int> &v, vector<int> &inv_l, vector<int> &inv_r, int l, int r)
{
    if(r<=l) return 0;
    int m = (l+r)/2;
    int ans = merge_sort(v, inv_l, inv_r, l, m) + merge_sort(v, inv_l, inv_r, m+1, r);

    int a = l, b = m+1;
    vector<int> sorted;

    int pending = 0;

    while(a<=m || b<=r)
    {
        if(a>m || (b<=r && v[b] < v[a]))
        {
            pending++;
            ans += m-a+1;
            sorted.pb(v[b]);
            inv_r[v[b]] += m-a+1;
            b++;
        }
        else
        {
            sorted.pb(v[a]);
            inv_l[v[a]] += pending;
            a++;
        }
    }

    for(int i = l ; i<=r ; i++) v[i] = sorted[i-l];

    return ans;
}

void solve(ll tc_no)
{
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n); inp(v);

    vector<int> inv_l(n+2), inv_r(n+2);
    int count = 0;
    count = merge_sort(v, inv_l, inv_r, 0, n-1);

    for(int i = 1 ; i<=n+1 ; i++) inv_l[i] += inv_l[i-1];
    for(int i = n ; i>=0 ; i--) inv_r[i] += inv_r[i+1];

    while(q--)
    {
        int l, r;
        cin >> l >> r;
        if(l==r)
        {
            cout << 0 << "\n";
        }
        else cout << count - inv_l[l] - inv_r[r] << "\n";
    }

    
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}