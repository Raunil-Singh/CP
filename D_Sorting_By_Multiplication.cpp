// 05-06-2025 22:56:36 (IST +0530)
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

vector<int> compute(vector<int> &v)
{
    int n = v.size();
    vector<int> res(n);
    int curr = 0;
    for(int i = 0 ; i<n ; i++)
    {
        res[i] = curr;
        if(i>0 && v[i-1] <= v[i]) curr++;
    }
    return res;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    if(n == 1)
    {
        cout << "0\n";
        return;
    }

    vector<int> decreasing = compute(v);
    reverse(all(v));
    vector<int> increasing = compute(v);
    reverse(all(v));
    reverse(all(increasing));

    int ans = INT_MAX;

    for(int i = 0 ; i<n ; i++)
    {
        int curr = decreasing[i] + increasing[i];
        if(i>0) curr++;
        if(((i>0 && v[i-1] <= v[i]) || i == 0) && ((i<n-1 && v[i+1] <= v[i]) || i == n-1)) curr++;
        ans = min(ans, curr);
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}