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
#define MOD 1000000007LL

int inv(int a, int m) { // m = MOD
    return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

vector<int> inv_mod;

void preprocessing()
{

    for(int i = 0 ; i<=100010 ; i++) inv_mod.pb(inv(i, MOD));

}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int a, b, k;
    cin >> a >> b >> k;

    int r = (k*(a-1) + 1) % MOD;

    int c = 1;
    for(int i = 1 ; i<=a ; i++) c = (c*(r-i+1) % MOD) * inv_mod[i] % MOD;

    c = (c * k) % MOD;
    c = (c * (b-1)) % MOD;
    c = (c + 1) % MOD;

    cout << r << " " << c << "\n";

}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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