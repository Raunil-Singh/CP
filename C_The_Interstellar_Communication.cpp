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

    int n;
    cin >> n;
    vector<vector<int>> a(n+2, vector<int>(35)), b(n+2, vector<int>(35));

    for(int i = 1 ; i<=n ; i++) {
        int num;
        cin >> num;
        for(int j = 0 ; j<35 ; j++) a[i][j] = a[i-1][j] + ((num>>j) & 1);
    }

    for(int i = 1 ; i<=n ; i++) {
        int num;
        cin >> num;
        for(int j = 0 ; j<35 ; j++) b[i][j] = b[i-1][j] + ((num>>j) & 1);
    }

    int q;
    cin >> q;

    for(int i = 1 ; i<=q ; i++) {
        int ans = 0;
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1++;
        r1++;
        l2++;
        r2++;
        for(int j = 0 ; j<35 ; j++) {
            int k = 0;
            k = ((r1-l1+1) - (a[r1][j]-a[l1-1][j])) * (b[r2][j]-b[l2-1][j]) + ((r2-l2+1) - (b[r2][j]-b[l2-1][j])) * (a[r1][j]-a[l1-1][j]);
            // cout << (k<<j) << "," << k << " ";
            ans += k<<j;
        }
        cout << ans << "\n";

    }



    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}