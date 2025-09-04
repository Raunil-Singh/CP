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

    double p;
    int n, t;
    cin >> n >> p >> t;

    vector<vector<double>> cnt(t+1, vector<double>(n+1, 0.0));
    cnt[0][0] = 1.0;

    for(int ti = 1 ; ti <= t ; ti++) {
        cnt[ti][0] = cnt[ti-1][0] * (1 - p);
        for(int x = 1 ; x < n ; x++) {
            cnt[ti][x] = cnt[ti-1][x] * (1-p) + cnt[ti-1][x-1] * p;
        }
        cnt[ti][n] = cnt[ti-1][n] + cnt[ti-1][n-1] * p;
    }

    double ans = 0;
    for(int x = 0 ; x <= n ; x++) {
        ans += x * cnt[t][x];
    }

    cout << ans << "\n";


    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}