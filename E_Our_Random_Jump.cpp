// B87678

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

void preprocessing()
{

    // Code here

}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> tele(a), time(b); inp(tele); inp(time);

    vector<double> l(n+1, -10), t(n+1, -10);

    l[n] = 1;
    t[n] = 0;

    for(int num : tele) {
        l[num] = 0;
        t[num] = 0;
        // cout << num << " ";
    }
    // cout << "\n";
    for(int num : time) {
        l[num] = 0;
        t[num] = 1;
        // cout << num << " ";
    }
    // cout << '\n';

    double sum_l = l[n], sum_t = t[n];
    for(int i = n-1 ; i>0 ; i--) {
        // cout << l[i] << " " << t[i] << "\n";
        if(l[i] < -1) {
            l[i] = sum_l/(n-i);
            t[i] = sum_t/(n-i);
        }
        sum_l += l[i];
        sum_t += t[i];
        // cout << l[i] << " " << t[i] << "\n";
    }
    cout << l[1] << " " << t[1] << " ";
    cout << l[1]/(1 - t[1]) << "\n";
    
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << fixed;
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