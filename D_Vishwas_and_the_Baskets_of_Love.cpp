// 10-06-2025 20:23:22 (IST +0530)
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

bool two_sum(vector<int> &v, int left, int right, int tar)
{
    while(left < right)
    {
        int curr = v[left] + v[right];
        if(curr == tar) return true;
        if(curr < tar) left++;
        else right--;
    }
    return false;
}

void solve(ll tc_no)
{
    
    int n, k;
    cin >> n >> k;

    vector<int> fc(n), fl(n); inp(fc); inp(fl);

    vector<int> a, b;
    for(int i = 0 ; i<n ; i++)
    {
        if(fl[i] == 8) a.pb(fc[i]);
        else b.pb(fc[i]);
    }

    sort(all(a));
    sort(all(b));

    int ans = 0;
    // all from a
    for(int i = 0 ; i<a.size() ; i++)
    {
        for(int j = i+1 ; j<a.size() ; j++)
        {
            if(two_sum(a, j, a.size()-1, k - a[i]))
            {
                cout << k << "\n";
                return;
            }
        }
    }

    // 2 from a
    for(int i = 0 ; i<a.size() ; i++)
    {
        for(int j = i+1 ; j<a.size() ; j++)
        {
            int pos = lower_bound(all(b), k - a[i] - a[j]) - b.begin();
            if(b.size() > pos && b[pos] == k - a[i] - a[j])
            {
                ans = max(ans, a[i] + a[j]);
            }
        }
    }

    // 1 from a
    for(int i = 0 ; i<b.size() ; i++)
    {
        for(int j = i+1 ; j<b.size() ; j++)
        {
            int pos = lower_bound(all(a), k - b[i] - b[j]) - a.begin();
            if(a.size() > pos && a[pos] == k - b[i] - b[j])
            {
                ans = max(ans, a[pos]);
            }
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}