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
#define MOD 1000000009

int inv(int a, int m) { // m = MOD
    return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

long long power(long long A, long long B)
{
    if (B == 0)
        return 1;

    long long res = power(A, B / 2) % MOD;

    if (B % 2)
        return (((res * res) % MOD) * A) % MOD;
    else
        return (res * res) % MOD;
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

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string s; cin >> s;

    int comp1 = power(a, n);

    int b_by_a = (b * inv(a, MOD))  % MOD;

    int num = 1;
    int x = power(b_by_a, k);

    int comp2 = ((power(x, (n+1)/k) - 1 + MOD) % MOD) * inv((x - 1 + MOD)%MOD, MOD) % MOD;

    int comp3 = 0;

    num = 1;
    for(int t = 0 ; t<k ; t++)
    {
        comp3 = (comp3 + (s[t] == '+' ? 1 : -1) * num + MOD) % MOD;
        num = (num * b_by_a) % MOD;
    }

    int ans = (comp1 * comp2 % MOD) * comp3 % MOD;
    cout << ans << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}