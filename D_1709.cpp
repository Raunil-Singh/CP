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
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);

    
    ordered_set<int> os;
    for(int i = 0 ; i<n ; i++)
    {
        int num; cin >> num;
        a[i] = mpr(num, os.size()-os.order_of_key(num));
        os.insert(num);
    }
    os = ordered_set<int>();
    for(int i = 0 ; i<n ; i++)
    {
        int num; cin >> num;
        b[i] = mpr(num, os.size()-os.order_of_key(num));
        os.insert(num);
    }

    sort(all(a));
    sort(all(b));

    vector<pair<int, int>> vp;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = a[i].S + i ; j>=i+1 ; j--)
        {
            vp.pb(mpr(1LL, j));
        }
    }


    for(int i = 0 ; i<n ; i++)
    {
        for(int j = b[i].S + i ; j>=i+1 ; j--)
        {
            vp.pb(mpr(2LL, j));
        }
    }


    for(int i = 0 ; i<n ; i++)
    {
        if(a[i].F > b[i].F)
        {
            vp.pb(mpr(3LL, i+1));
        }
    }


    cout << vp.size() << "\n";
    for(auto  p : vp) cout << p.F << " " << p.S << "\n";
    
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
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}