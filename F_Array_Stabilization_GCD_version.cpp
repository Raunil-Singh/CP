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

vector<int> leastPrimeFactor(int n)
{
    vector<int> least_prime(n+1, 0); 
    least_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;
 
            for (int j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }

    return least_prime;
}

vector<int> spf(1000'010);

inline void preprocessing() {

    spf = leastPrimeFactor(1000'010);

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    int g = v[0];
    for(int num : v) g = gcd(g, num);
    for(int &num : v) num /= g;

    map<int, vector<int>> facts;
    for(int i = 0 ; i<n ; i++) {
        int num = v[i];
        int prev = 1;
        while(num > 1) {
            int curr = spf[num];
            num /= curr;
            if(prev == curr) continue;
            facts[curr].push_back(i);
            facts[curr].push_back(n+i);
            prev = curr;
        }
    }

    int ans = 0;
    vector<int> cnt(2*n);
    for(auto &[a, b] : facts) {
        sort(all(b));
        int N = b.size();
        if(N == 2*n) continue;
        // cout << a << " -> ";
        for(int i = 0 ; i<N ; i++) {
            cnt[i] = 1;
            if(i!=0 && b[i-1] == b[i] - 1) cnt[i] = cnt[i-1]+1;
            // cout << b[i] << ":" << cnt[i] << ", ";
        }
        // cout << "\n";
        int curr = *max_element(cnt.begin(), cnt.begin() + N);
        if(curr >= n) curr = 0;
        ans = max(ans, curr);
    }

    cout << ans << "\n";


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