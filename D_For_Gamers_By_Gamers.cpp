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

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, C;
    cin >> n >> C;

    vector<pair<int, int>> vp(n);
    for(int i = 0 ; i<n ; i++) {
        int c, h, d;
        cin >> c >> d >> h;
        vp[i] = mpr(h*d, c);
    }

    sort(all(vp));

    vector<int> mc(n), hd(n);
    for(int i = 0 ; i<n ; i++) {
        mc[i] = vp[i].S;
        hd[i] = vp[i].F;
        // cout << hd[i] << " " << mc[i] << "**\n";
    }

    for(int i = n-2 ; i>=0 ; i--) {
        mc[i] = min(mc[i], mc[i+1]);
    }

    for(int i = 0 ; i<n ; i++) {
        cout << hd[i] << " " << mc[i] << "\n";
    }

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int ind = lower_bound(all(hd), a*b + 1) - hd.begin();
        if(ind == n) {
            cout << "-1 ";
        }
        else cout << mc[ind] << " ";
    }
    cout << "\n";
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}