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

#define int int64_t // upto 9.2 * (10^18)
#define uint uint64_t // upto 1.8 * (10^19)
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, q;
    cin >> n >> q;

    vector<string> vs(n); inp(vs);
    vector<vector<int>> cnt(n+1, vector<int>(n+1));

    for(int i = 1 ; i<=n ; i++) {
        for(int j = 1 ; j<=n ; j++) {
            if(vs[i-1][j-1] == '*') cnt[i][j] = 1;
        }
    }

    for(int i = 1 ; i<=n ; i++) {
        for(int j = 1 ; j<=n ; j++) cnt[i][j] += cnt[i][j-1] + cnt[i-1][j] - cnt[i-1][j-1];
    }

    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << cnt[c][d] - cnt[a-1][d] - cnt[c][b-1] + cnt[a-1][b-1] << "\n";
    }

}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    // cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}