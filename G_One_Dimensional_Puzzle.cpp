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
#define MOD ((int64_t)998244353)

#define LIM 7000000

int inv_for_nCr(int a, int m = MOD) { // m = MOD
    return a <= 1 ? a : m - (long long)(m/a) * inv_for_nCr(m % a, m) % m;
}

vector<int> factorial;
vector<int> inverse_factorial;

void precompute_for_nCr(int x) // call this to get precompute
{
    factorial.resize(x+1);
    inverse_factorial.resize(x+1);

    factorial[0] = 1;
    inverse_factorial[0] = inv_for_nCr(1, MOD);
    for(int i = 1 ; i<=x ; i++)
    {
        factorial[i] = (factorial[i-1]*i) % MOD;
        inverse_factorial[i] = (inverse_factorial[i-1]*inv_for_nCr(i, MOD)) % MOD;
    }
}

int nCr(int n, int r)
{
    return (factorial[n] * ((inverse_factorial[r]*inverse_factorial[n-r]) % MOD)) % MOD;
}

void preprocessing() {

    precompute_for_nCr(LIM);
 
}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    vector<int> c(4); inp(c);

    if(abs(c[0] - c[1]) > 1) {
        cout << "0\n";
        return;
    }

    int ans = 0;

    // start with 0
    if(c[0] >= c[1] && c[0]) {
        ans = (ans + max((int)1, nCr(c[0] - 1 + c[2], c[2]) * nCr(c[1] + c[3], c[3]) % MOD)) % MOD;
    }

    // cout << ans << " ";

    // start with 1
    if(c[1] >= c[0] && c[1]) {
        ans = (ans + max((int)1, nCr(c[0] + c[2], c[2]) * nCr(c[1] -1 + c[3], c[3]) % MOD)) % MOD;
    }

    if(c[0] == 0 && c[1] == 0) {
        if(c[2] == 0 || c[3] == 0) ans = 1;
    }

    cout << ans << "\n";

}

/*
    abs(count of 1 - count 2) <= 1

    So, I create a chain of either 1212121... or 21212121...
    Then insert 3 and 4 in it.
    

*/

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