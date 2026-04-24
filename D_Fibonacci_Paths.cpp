#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <utility>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

// #define int int64_t // upto 9.2 * (10^18)
#define uint uint64_t // upto 1.8 * (10^19)
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD ((int)998244353)

#define LB 1048575

void preprocessing() {

    // Code here

}

inline int gen(int a, int b) {
    return ((a<<20) | b);
}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int64_t n, m;
    cin >> n >> m;

    vector<int64_t> v(n); inp(v);

    map<int64_t, int> edge;
    map<pair<int, int64_t>, int> cu; // cumulative <first_node_index, second_node_val> -> number of ways to end at first node that lead to second node.
    vector<pair<int64_t, pair<int, int>>> vpp;
    vpp.reserve(m);
    for(int i = 0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a*n + b] = 1;
        vpp.push_back(make_pair(v[a]+v[b], make_pair(a, b)));
    }

    sort(all(vpp));

    int ans = 0;

    for(auto &[curr_val, curr_edge] : vpp) {
        int a = curr_edge.first;
        int b = curr_edge.second;
        int64_t x = a*n + b;
        int y = edge[x] + cu[make_pair(a, v[b])];
        cu[make_pair(b, curr_val)] = (cu[make_pair(b, curr_val)] + y) % MOD;
        ans = (ans + y) % MOD;
    }

    cout << ans << "\n";

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
    cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}