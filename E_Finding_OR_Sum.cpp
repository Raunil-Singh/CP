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

int x1, x2;

void pre_process()
{
    for(int i = 0 ; i<30 ; i++)
    {
        if(i&1) x1 += (1<<i);
        else x2 += (1<<i);
    }
}

void solve(ll tc_no)
{
    int n1, n2;
    cout << x1 << "\n";
    cin >> n1;
    cout << x2 << "\n";
    cin >> n2;

    vector<int> v(31, 0);
    for(int i = 0 ; i<30 ; i++)
    {
        if(i&1) // n2
        {
            v[i] = (n2&3) - 1;
            n2 >>= 2;
        }
        else // n1
        {
            v[i] = n1&3;
            v[i] -= (i!=0);
            n1 >>= 2;
        }
    }

    int m;
    cout << "!\n";

    int ans = 0;
    int carry = 0;
    for(int i = 0 ; i<30 ; i++)
    {
        if(m&(1<<i))
            v[i] = 2;
        v[i] += carry;
        ans += v[i]*(1<<i);
    }

    cout << ans << "\n";

}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    x1 = 0;
    x2 = 0;

    pre_process();

    cout << x1+x2 << "##\n";

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}