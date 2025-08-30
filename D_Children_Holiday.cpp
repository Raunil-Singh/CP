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

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void check(vector<ull>&t, vector<ull>&z, vector<ull>&y, vector<ull> &sol, ull time)
{
    // cout << time << " # ";
    ull n = t.size();
    for(ull i = 0 ; i<n ; i++)
    {
        sol[i] = z[i]*(time/(t[i]*z[i] + y[i])) + min((time%(t[i]*z[i] + y[i]))/t[i], z[i]);
        // cout << sol[i] << " ";
    }
    // cout << "\n";
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

    ull m, n;
    cin >> m >> n;

    vector<ull> t(n), z(n), y(n), sol(n);
    for(ull i = 0 ; i<n ; i++) cin >> t[i] >> z[i] >> y[i];

    ull l = 0, r = ULLONG_MAX;
    while(l < r)
    {
        ull mid = l + (r-l)/2;
        check(t, z, y, sol, mid);
        if(accumulate(all(sol), 0LL) >= m) r = mid;
        else l = mid+1;
        // cout << l << " " << r << " !\n";
    }

    cout << r << "\n";
    check(t, z, y, sol, r);

    for(ull &num : sol)
    {
        num = min(m, num);
        m -= num;
        cout << num << " ";
    }
    cout << "\n";

    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}