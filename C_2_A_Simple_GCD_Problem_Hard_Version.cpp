#include <algorithm>
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


vector<int> primes;

vector<int> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);

    for(int p = 2; p * p <= n; p++) {
        if(prime[p] == true) {
            for(int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<int> res;

    for (int p = 2; p <= n; p++)
        if (prime[p])
            res.push_back(p);
    
    return res;
}

inline void preprocessing() {

    primes = SieveOfEratosthenes(1000000);

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> a(n), b(n); inp(a); inp(b);

    vector<array<int, 3>> vp(n);
    for(int i = 0 ; i<n ; i++) {
        int x = 0;
        int num = a[i];
        for(int i = 2 ; i*i<=a[i] ; i++) {
            if(num % i == 0) {
                x++;
                while(num % i == 0) num /= i;
            }
        }
        vp[i] = {x, a[i], i};
    }

    sort(all(vp), greater());

    int ans = 0;
    for(auto [t, x, y] : vp) {
        int num = 1;
        if(y > 0) num = lcm(gcd(x, a[y-1]), num); 
        if(y < n-1) num = lcm(gcd(x, a[y+1]), num);
        if(num <= b[y] && num != a[y]) {
            a[y] = num;
            ans++;
            // cout << x << "->" << num << ' ';
            continue;
        }
        int pos = min((int)(primes.size()-1), (int)(lower_bound(all(primes), b[y]/num) - primes.begin()));
        for(int i = pos ; i>=0 ; i--) {
            int p = primes[i];
            if(y > 0 && gcd(a[y-1], num*p) != gcd(a[y-1], x)) continue;
            if(y < n-1 && gcd(a[y+1], num*p) != gcd(a[y+1], x)) continue;
            if(num * p <= b[y]) {
                num = num*p;
                a[y] = num;
                ans++;
                // cout << x << "->" << num << ' ';
                break;
            }
        }
    }

    // cout << "\n";

    cout << ans << "\n";

    

}
// Note: Ensure all template parameters are updated!

/****              Algorithm keypoints:
    here:
    
    

    for(int i = 1 ; i<n ; i++) {
        tar[i-1] = lcm(tar[i-1], gcd(a[i], a[i-1]));
    }
    for(int i = 0 ; i<n-1 ; i++) {
        tar[i+1] = lcm(tar[i+1], gcd(a[i], a[i+1]));
    }

    int ans = 0;
    vector<bool> flag(n);

    for(int i = 0 ; i<n ; i++) {
        if(tar[i] > b[i]) {
            tar[i] = a[i];
        }
    }

    for(int p : primes) {
        for(int i = 0 ; i<n ; i++) {
            if(tar[i] != a[i]) continue;
            int new_num = tar[i] * p;
            if((i==0 || a[i-1] % p != 0) && (i==n-1 || a[i+1] % p != 0) && new_num != a[i] && new_num < b[i]) {
                tar[i] = new_num;
            }
        }
    }

    for(int i = 0 ; i<n ; i++) ans += (tar[i] != a[i] && tar[i] <= b[i]);

    // for(int x : tar) cout << x << " ";
    // cout << "\n";

    cout << ans << "\n";
    
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