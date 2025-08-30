// 03-06-2025 18:14:06 (IST +0530)
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

int n1, n2;

void preprocessing()
{
    n1 = 0;
    n2 = 0;
    for(int i = 0 ; i<30 ; i++)
    {
        if(i&1) n1 ^= (1<<i);
        else n2 ^= (1<<i);
    }
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    cout << n1 << endl;
    int resp1; cin >> resp1;
    cout << n2 << endl;
    int resp2; cin >> resp2;

    resp1 += 1;

    vector<int> sums(30);
    for(int i = 0 ; i<30 ; i++)
    {
        int num = 0;
        if(i&1) num = ((resp2>>i)&3) - 1;
        else num = ((resp1>>i)&3) - 1;
        sums[i] += num;
    }

    cout << "! " << endl;
    int resp; cin >> resp;

    int ans = 0;
    for(int i = 0 ; i<30 ; i++)
    {
        if(resp & (1<<i)) ans += 2<<i;
        else ans += sums[i]<<i; 
    }

    cout << ans << endl;
    
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

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}