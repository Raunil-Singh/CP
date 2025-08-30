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


int res(int n, int k, int x, int a, int b, int c, int bit)
{
    deque<pair<int, int>> q; // <val, ind>
    q.pb(mpr(x & bit, 1LL));
    int res = (k==1 ? q.front().F : 0);
    for(int i = 2 ; i<=n ; i++)
    {
        x = (a*x + b) % c;
        int curr = x & bit;
        while(q.size() && q.back().F < curr) q.ppb();
        q.pb(mpr(curr, i));
        while(q.front().S < i-k+1) q.pop_front();
        if(i>=k)
            res ^= q.front().F;
    }
    return res;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    // code here
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    int ans = 0;
    for(int i = 1LL<<31 ; i>0 ; i>>=1)
        ans |= res(n, k, x, a, b, c, i);
    cout << ans << "\n";
    
    return 0;
}