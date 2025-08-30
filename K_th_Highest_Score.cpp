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

// map<pair<char, int>, int> qs;

int query(char c, int pos, int n)
{
    if(pos <= 0) return INT_MAX;
    else if(pos > n) return INT_MIN;
    int ans;
    // if(qs.find(mpr(c, pos))!=qs.end()) ans = qs[mpr(c, pos)];
    // else
    // {
        cout << c << " " << pos << "\n";
        cin >> ans;
        // qs[mpr(c, pos)] = ans;
    // }
    return ans;
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    // code here
    int n, k;
    cin >> n >> k;

    int l = 0, r = n+1;
    while(l+1<r)
    {
        int m1 = (l+r)/2;
        int m2 = k-m1;
        if(query('F', m1, n) < query('S', m2+1, n)) r = m1;
        else if(query('S', m2, n) < query('F', m1+1, n)) l = m1;
        else
        {
            l = m1;
            r = m1+1;
        }
    }
    int ans = -1;
    ans = min(query('F', l, n), query('S', k-l, n));
    cout << "! " << ans << "\n";
    return 0;
}