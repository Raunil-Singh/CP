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

#define int long long // upto 9.2 * (10^18)
#define uint unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

void preprocessing()
{

    // Code here

}

void solve(int tc_no)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for(int i = 1 ; i<=n ; i++) cin >> a[i];
    for(int i = 1 ; i<=m ; i++) cin >> b[i];

    sort(all(a));
    sort(all(b));
    
    vector<int> pref(m+2), suff(m+2);
    for(int i = 1 ; i<=m ; i++) pref[i] = pref[i-1] + b[i];
    for(int i = m ; i>0 ; i--) suff[i] = suff[i+1] + b[i];

    vector<pair<int, int>> vp;
    for(int i = 1 ; i<=n ; i++) vp.pb(mpr(a[i], 1));
    for(int i = 1 ; i<=m ; i++) vp.pb(mpr(b[i], 0));

    sort(all(vp));

    int curr = 0;
    int sum = 0;
    int tot = accumulate(all(a), 0LL);

    int ans = 0;

    for(int i = 1 ; i<=vp.size() ; i++) {
        if(vp[i-1].S == 1) {
            curr++;
            sum += vp[i-1].F;
        }
        if(i - curr >= n - curr && curr <= (vp.size() - i) - (n - curr)) {
            ans = max(ans, tot - 2*sum + suff[m - curr + 1] - pref[n - curr]);
        }
    }

    cout << ans << "\n";
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

    int t;
    cin >> t;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}