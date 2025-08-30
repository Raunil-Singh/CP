// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

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

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-8;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

pair<long double, long double> calculate(vector<long double>&x, vector<long double>&v, long double t)
{
    int n = v.size();
    long double x1, x2;
    x1 = x[0] - t*v[0];
    x2 = x[0] + t*v[0];
    for(int i = 0 ; i<n ; i++)
    {
        x1 = max(x[i] - t*v[i], x1);
        x2 = min(x[i] + t*v[i], x2);
    }
    return mpr(x1, x2);
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << fixed;
    cout << setprecision(20);

    int n;
    cin >> n;
    vector<long double> x(n), v(n);
    for(int i = 0 ; i<n ; i++) cin >> x[i] >> v[i];

    long double l = -10, r = (*max_element(all(x)) - *min_element(all(x)) + 1) / (*min_element(all(v)));
    while(r-l > eps)
    {
        long double mid = (l+r)/2;
        auto [x1, x2] = calculate(x, v, mid);
        if(x1-eps < x2 + eps) r = mid;
        else l = mid;
    }

    cout << r << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}