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
#define MOD ((int)998244353)

void preprocessing() {

    // Code here

}

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

int expo(int a, int p) {
    if(p < 0) return 0;
    if(p == 0) return 1;
    if(a == 0) return 0;
    if(p & 1) return mul(a, expo(mul(a, a), p/2)) % MOD;
    else return expo(mul(a, a), p/2);
}

void solve(int tc_no) {
    
    int n, k;
    cin >> n >> k;
    
    if(n == 1) {
        cout << "0\n";
        return;
    }

    int ans = 0;

    int prod = 1;

    for(int i = 0 ; i<k && n-i-1 >= 1 ; i++) {
        prod = mul(prod, k-i);
        int x = add(expo(k-i, n-1-i), MOD - expo(k-i-1, n-1-i));
        // cout << expo(k-i, n-1-i) << " " << expo(k-i-1, n-1-i) << "\n";
        int curr = mul(prod, x);
        int res = mul(i+1, curr);
        // cout << (i+1) << ":" << curr << ":" << res << " ";
        ans = add(ans, res);
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


/*

k k-1 k-1 k-1 k-1 k-1 k-1 _ * 1

1-> k:1 _ k:n-2, k:1 k-1:1 _ k:n-3 

k k-1 k-2 _ k-1 k-1 k-1 k-1 * 2

*/