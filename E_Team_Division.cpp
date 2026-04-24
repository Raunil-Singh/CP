#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define MOD ((int64_t) 998244353)

int inv_for_nCr(int a, int m) { // m = MOD
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

inline void preprocessing() {

    precompute_for_nCr(1000000);

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;

    vector<int> cnt(n+1);
    vector<int> v(n+2);

    for(int i = 0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b+1]--;

        if(a <= (n/2) && n-(n/2) <= b) {
            int l = 0, r = n/2;
            while(l+1 < r) {
                int mid = (l+r)/2;
                if(a <= mid && n-mid <= b) r = mid;
                else l = mid;
            }
            // cout << a << ' ' << b << " -> " << r << "\n";
            cnt[r]++;
            cnt[n-r+1]--;
        }
    }

    for(int i = 1 ; i<=n+1 ; i++) v[i] += v[i-1];
    for(int i = 1 ; i<=n ; i++) cnt[i] += cnt[i-1];

    int ans = 0;

    for(int i = 1 ; i<n ; i++) {
        int a = v[i] - cnt[i], b = v[n-i] - cnt[i], c = cnt[i];
        // cout << i << " -> " << a << " " << b << " " << c << "\n";
        if(a + b + c != n) continue;
        int t = i - a;
        if(t >= 0 && t <= c) ans = (ans + nCr(c, t)) % MOD;
    }

    cout << ans << '\n';

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
    // cin >> t; // Update me!
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