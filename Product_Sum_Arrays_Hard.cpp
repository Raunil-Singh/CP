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
    int n;
    cin >> n;

    set<int> factors;
    if(n != 1) factors.insert(n);
    for(int i = 2 ; i*i<=n ; i++) {
        if(n % i != 0) continue;
        factors.insert(n/i);
        factors.insert(i);
    }

    // for(int fact : factors) cout << fact << " ";
    // cout << "\n";

    // cout << "Processing...\n";
    map<int, int> mpp;
    mpp[1] = 1;
    for(auto fact : factors) {
        map<int, int> temp;
        for(auto [a, b] : mpp) {
            int curr = a;
            while(n % (curr * fact) == 0) {
                temp[curr * fact] += b;
                curr *= fact;
            }
        }
        for(auto [a, b] : temp) {
            mpp[a] += b;
        }
        // cout << fact << " Done\n";
    }

    cout << mpp[n] << "\n";
    
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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