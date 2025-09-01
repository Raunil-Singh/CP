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
#define MOD

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << fixed;
    cout << setprecision(10);

    // code here
    int n, a, b;
    cin >> n >> a >> b;

    vector<double> d(n+1, 1.0);
    d[0] = 0;
    
    vector<double> sum_d(n+1, 0.0);
    
    if(a == 0) {
        for(int i = 1 ; i<=n ; i++) {
            double del = sum_d[i-1] - (i-b-1 >= 0 ? sum_d[i-b-1] : 0);
            d[i] = 1.0 + (1.0 + del)/b;
            sum_d[i] = d[i] + sum_d[i-1];    
        }
    } else {
        for(int i = 1 ; i<=n ; i++) {
            double del = (i-a >= 0 ? sum_d[i-a] : 0) - (i-b-1 >= 0 ? sum_d[i-b-1] : 0);
            d[i] = 1.0 + (del)/(b - a + 1);
            sum_d[i] = d[i] + sum_d[i-1];    
        }
    }

    // for(int i = 0 ; i<=n ; i++) cout << i << " -> " << d[i] << "\n";

    cout << d[n] << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}