// 05-06-2025 23:29:56 (IST +0530)
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

bool check1(vector<int> &v, int &cost)
{
    int n = v.size();
    int least = *min_element(all(v));
    int most = *max_element(all(v));
    if(least == most)
    {
        cost = 0;
        return true;
    }
    int st = -1;
    if(v[0] < v.back()) st = 0;
    else for(int i = 1 ; i<n ; i++) if(v[i-1] == most && v[i] == least) {
        st = i;
        break;
    }
    if(st == -1) return false;
    int prev = -1;
    for(int i = st ; i<st+n ; i++) if(v[i%n] < prev) return false; else prev = v[i%n];

    cost = min(n-st, (st ? 2+st : 0));
    return true;
}
bool check2(vector<int> &v, int &cost)
{
    reverse(all(v));
    int n = v.size();
    int least = *min_element(all(v));
    int most = *max_element(all(v));
    if(least == most)
    {
        cost = 0;
        return true;
    }
    int st = -1;
    if(v[0] < v.back()) st = 0;
    else for(int i = 1 ; i<n ; i++) if(v[i-1] == most && v[i] == least) {
        st = i;
        break;
    }
    if(st == -1) return false;
    int prev = -1;
    for(int i = st ; i<st+n ; i++) if(v[i%n] < prev) return false; else prev = v[i%n];

    cost = min(n-st+1, (st ? 1+st : 1));
    return true;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    int ans = INT_MAX;
    bool flag = true;
    int c = -10;
    if(check1(v, c))
    {
        ans = min(ans, c);
    }
    if(check2(v, c))
    {
        ans = min(ans, c);
    }
    
    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans << "\n";
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