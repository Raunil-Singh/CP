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

#define max_k 1000000000LL

void preprocessing()
{

    // Code here

}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i = 0 ; i<n ; i++) {
        int x, y;
        cin >> x >> y;
        vp[i] = mpr(x, y);
    }

    int p1 = 0, p2 = 0, mx1 = ((int)INT_MIN) * 2, mx2 = ((int)INT_MIN) * 2;
    for(int i = 0 ; i<n ; i++) {
        if(vp[i].F + vp[i].S > mx1 || (vp[i].F + vp[i].S == mx1 && vp[i].S < vp[p1].S)) {
            mx1 = vp[i].F + vp[i].S;
            p1 = i;
        }
        if(vp[i].F - vp[i].S > mx2 || (vp[i].F - vp[i].S == mx2 && vp[i].S > vp[p2].S)) {
            mx2 = vp[i].F - vp[i].S;
            p2 = i;
        }
    }

    int x = vp[p2].F - vp[p1].F, y = vp[p2].S - vp[p1].S;

    int t, l;
    cout << "? D " << max_k << endl;
    cin >> t;
    cout << "? D " << max_k << endl;
    cin >> t;
    cout << "? R " << max_k << endl;
    cin >> t;
    cout << "? R " << max_k << endl;
    cin >> t;
    int d = max_k * 4;
    cout << "? U " << max_k << endl;
    cin >> l;
    cout << "? U " << max_k << endl;
    cin >> l;
    cout << "? U " << max_k << endl;
    cin >> l;
    cout << "? U " << max_k << endl;
    cin >> l;

    int a = (d + t - x - y - l) / 2;
    int b = t - a;

    int init_x = vp[p1].F + b, init_y = vp[p1].S - a;
    init_x -= max_k * 2;
    init_y += max_k * 2;

    // if(abs(init_x) > max_k || abs(init_y) > max_k) cout << "! 0 0" << endl;
    cout << "! " << init_x << ' ' << init_y << endl;

}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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