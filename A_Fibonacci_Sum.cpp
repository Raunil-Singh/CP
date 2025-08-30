// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
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

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void solve(ll tc_no)
{
    
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    map<int, int> count;
    for(int &num : v) count[num]++;

    int c1 = 0;

    for(int &num : v)
    {
        int x = count[num-1];
        int y = count[num-3];
        c1 += x * (x-1) * y / 2;
    }

    int temp = 0;

    int c2 = 0;
    for(auto [a, b] : count)
    {
        int curr = b*(b-1)/2;
        c2 += curr * temp;
        temp += curr;
    }

    int c3 = 0;
    for(auto [a, b] : count)
    {
        c3 += b*(b-1)*(b-2)*(b-3)/24;
    }

    // cout << c1 << " " << c2 << " " << c3 << " \n";
    cout << c1 + c2 + c3 << "\n"; 
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}