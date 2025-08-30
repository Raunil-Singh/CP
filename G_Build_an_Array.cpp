// 10-06-2025 23:39:51 (IST +0530)
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

void preprocessing()
{

    // Code here

}

void solve(ll tc_no)
{
    
    // cout << "Case " << tc_no << " : \n";
    int n, k;
    cin >> n >> k;
    vector<int> v(n); inp(v);

    vector<int> left(n);
    for(int i = 1 ; i<n ; i++)
    {
        int num = v[i-1];
        int moves = 0;
        int count = 1;
        while(!(num&1))
        {
            if(v[i]*2 == num)
            {
                moves = 1;
                count --;
            }
            num >>= 1;
            count <<= 1;
        }

        moves += count;

        left[i] = moves + left[i-1];
    }

    vector<int> right(n);
    for(int i = n-2 ; i>=0 ; i--)
    {
        int num = v[i+1];
        int moves = 0;
        int count = 1;
        while(!(num&1))
        {
            if(v[i]*2 == num)
            {
                moves = 1;
                count --;
            }
            num >>= 1;
            count <<= 1;
        }

        moves += count;

        right[i] = moves + right[i+1];
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++)
    {
        int num = v[i];
        int moves = 1;
        while(!(num&1))
        {
            moves <<= 1;
            num >>= 1;
        }
        ans = max(left[i] + right[i] + moves, ans);
        // cout << left[i] + right[i] + moves << " ";
    }
    // cout << "\n";

    // for(int num : left) cout << num << " ";
    // cout << "\n";

    // for(int num : right) cout << num << " ";
    // cout << "\n";

    if(ans >= k && n<=k) cout << "YES\n";
    else cout << "NO\n";

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