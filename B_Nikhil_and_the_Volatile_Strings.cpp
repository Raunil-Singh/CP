#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#define FAST_IO ;
#else
#define dbg(x, ...) ;
#endif

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
#define MOD ((int64_t) 1'000'000'007)

struct Mint
{
    int value;
    static const int MOD_value = MOD;
 
    Mint(long long v = 0)
    {
        value = v % MOD;
        if (value < 0)
            value += MOD;
    }
    Mint(long long a, long long b) : value(0)
    {
        *this += a;
        *this /= b;
    }
 
    Mint &operator+=(Mint const &b)
    {
        value += b.value;
        if (value >= MOD)
            value -= MOD;
        return *this;
    }
    Mint &operator-=(Mint const &b)
    {
        value -= b.value;
        if (value < 0)
            value += MOD;
        return *this;
    }
    Mint &operator*=(Mint const &b)
    {
        value = (long long)value * b.value % MOD;
        return *this;
    }
 
    friend Mint mexp(Mint a, long long e)
    {
        Mint res = 1;
        while (e)
        {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }
 
    Mint &operator/=(Mint const &b) { return *this *= inverse(b); }
    friend Mint operator+(Mint a, Mint const b) { return a += b; }
    friend Mint operator-(Mint a, Mint const b) { return a -= b; }
    friend Mint operator-(Mint const a) { return 0 - a; }
    friend Mint operator*(Mint a, Mint const b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const b) { return a /= b; }
    friend std::ostream &operator<<(std::ostream &os, Mint const &a) { return os << a.value; }
    friend bool operator==(Mint const &a, Mint const &b) { return a.value == b.value; }
    friend bool operator!=(Mint const &a, Mint const &b) { return a.value != b.value; }
};

Mint fact[250];

inline void preprocessing() {

    // Code here
    fact[0] = 0;
    for(int i = 1 ; i<230 ; i++) fact[i] *= i;

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    vector<int> v(26); inp(v);

    

}
// Note: Ensure all template parameters are updated!

/****              Algorithm keypoints:
    here:
    
    
    
****/

int32_t main() {
    #ifdef BG
    auto begin = std::chrono::high_resolution_clock::now();
    #else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    #ifdef BG
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif

    return 0;
}


// ======= CHECKLIST =======
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)