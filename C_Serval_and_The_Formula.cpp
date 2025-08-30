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
    
    int x, y;
    cin >> x >> y;

    int k = 0;
    int whichone = -1;
    int prev = 0;
    int fact = 1;
    while(x > 0 || y > 0)
    {
        // cout << x << " " << y << " " << fact << " " << prev << "#\n";

        if(x == 1 && y == 1 && prev == 0)
        {
            cout << "-1\n";
            return;
        }

        int a = x&1, b = y&1;
        
        if(a == 1 && b == 1)
        {
            k += fact - prev;
            x++;
            y++;
            if(whichone == 1) y--;
            if(whichone == 0) x--;    
        }
        else if(a+b == 1 && ((x&2) + (y&2) == 4))
        {
            x++;
            y++;
            k += fact;
        }

        if((x&1) + (y&1) == 1)
        {
            prev = fact;
            if(x&1) whichone = 1;
            else if(y&1) whichone = 0;
        }
        
        fact <<= 1;
        x >>= 1;
        y >>= 1;
    }

    cout << k << "\n";
    
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