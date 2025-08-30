// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> vp(n);
    ordered_set<int> os1, os2;
    
    for(int i = 0 ; i<n ; i++)
    {
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b, i};
        os1.insert(b);
    }

    sort(all(vp), [](auto &a, auto &b)->bool {
        auto [a1, a2, a3] = a;
        auto [b1, b2, b3] = b;
        if(a1!=b1) return a1 < b1;
        else return a2 > b2;
    });

    vector<int> ans1(n);
    for(auto [a, b, c] : vp)
    {
        os1.erase(os1.find_by_order(os1.order_of_key(b)));
        ans1[c] = os1.order_of_key(b+1);
    }

    vector<int> ans2(n);
    for(auto [a, b, c] : vp)
    {
        ans2[c] = os2.size() - os2.order_of_key(b);
        // cout << a << " " << b << " " << ans2[c] << "#\n";
        os2.insert(b);
    }

    for(int num : ans1) cout << num << " ";
    cout << "\n";
    for(int num : ans2) cout << num << " ";
    cout << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}