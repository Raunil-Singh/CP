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

class Solution
{
private :

    int l1, r1, l2, r2;
        
    int compute(int a1, int b1, int a2, int b2, int l1, int r1, int l2, int r2)
    {
        if(a1>=b1 || a2>=b2 || l1>=r1 || l2>=r2) return 0;
        if(a1==l1 && b1==r1 && a2==l2 && b2==r2) return 1;

        // cout << a1 << " " << b1 << " " << a2 << " " << b2 << " " << l1 << " " << r1 << " " << l2 << " " << r2 << " #\n"; 

        int m1 = (a1+b1)/2, m2 = (a2+b2)/2;
        return  compute(a1, m1, a2, m2, l1, min(m1, r1), l2, min(m2, r2))
            +   compute(m1, b1, m2, b2, max(m1, l1), r1, max(m2, l2), r2)
            +   compute(a1, m1, m2, b2, l1, min(m1, r1), max(m2, l2), r2)
            +   compute(m1, b1, a2, m2, max(m1, l1), r1, l2, min(m2, r2));
    }

public :
    void solve(ll tc_no)
    {
        
        cin >> l1 >> r1 >> l2 >> r2;

        int b1 = 1, b2 = 1;
        while(b1 < r1) b1 <<= 1;
        while(b2 < r2) b2 <<= 1;

        cout << compute(0, max(b1, b2), 0, max(b1, b2), l1, r1, l2, r2) << "\n";

    }
};

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
    {
        Solution obj;
        obj.solve(i);
    }
    return 0;
}