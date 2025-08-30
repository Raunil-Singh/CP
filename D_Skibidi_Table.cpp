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

void preprocessing()
{

    // Code here

}

int q1(int x, int y, int n)
{
    if(x == 1 && y == 1) return 1;
    int t = (1<<n);
    if(x<=t && y<=t) return (t*t)*(0) + q1(x, y, n-1);
    if(x> t && y> t) return (t*t)*(1) + q1(x-t, y-t, n-1);
    if(x> t && y<=t) return (t*t)*(2) + q1(x-t, y, n-1);
    if(x<=t && y> t) return (t*t)*(3) + q1(x, y-t, n-1);
}

pair<int, int> q2(int x, int n)
{
    if(x == 1) return mpr(1, 1);
    int t = (1<<n);
    if(x <= t*t) return q2(x, n-1);
    if(x <= 2*t*t)
    {
        pair<int, int> p = q2(x - t*t, n-1);
        return mpr(t + p.F, t + p.S);
    }
    if(x <= 3*t*t)
    {
        pair<int, int> p = q2(x - 2*t*t, n-1);
        return mpr(t + p.F, p.S);
    }
    else
    {
        pair<int, int> p = q2(x - 3*t*t, n-1);
        return mpr(p.F, t + p.S);
    }
}

void solve(ll tc_no)
{
    
    int n;
    cin >> n;
    int q;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        if(s == "->")
        {
            int a, b;
            cin >> a >> b;
            cout << q1(a, b, n) << "\n";
        }
        else
        {
            int x;
            cin >> x;
            pair<int, int> p = q2(x, n);
            cout << p.F << " " << p.S << "\n";
        }
    }

}

signed main()
{
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

    return 0;
}