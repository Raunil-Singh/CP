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
    int n{}, q{};
    cin >> n >> q;

    vector<int> v(n+1);
    for(int i{1} ; i<=n ; i++) cin >> v[i];

    vector<int> sum(n+1), cnt(n+1);
    for(int i = 1 ; i<=n ; i++) {
        sum[i] = sum[i-1] + v[i];
        cnt[i] = cnt[i-1] + (v[i] == 1 ? 1 : 0);
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        
        int curr_s {sum[b] - sum[a-1]}, curr_c {cnt[b] - cnt[a-1]};
        int elec {b-a+1};

        // cout << curr_s << " " << curr_c << " " << elec << "\n";

        if(elec == curr_c || (curr_s - elec < curr_c) || elec == 1) cout << "NO\n";
        else cout << "YES\n";
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

    int t{};
    cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}