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

void solve(ll tc_no)
{
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n); inp(a);
    vector<int> b(m); inp(b);

    sort(all(b));

    int mp = a[n-1];
    for(int num : b) mp = max(mp, num-a[n-1]);
    a[n-1] = mp;

    // cout << a[n-1] << " ";

    for(int i = n-2 ; i>=0 ; i--)
    {
        // cout << a[i] << " ";
        int pos = (upper_bound(all(b), a[i] + a[i+1]) - b.begin());
        if(pos == 0 && a[i] > a[i+1])
        {
            cout << "NO\n";
            return;
        }
        if(pos == 0) continue;
        pos--;
        if(a[i] > a[i+1] || (a[i] < b[pos]-a[i] && b[pos]-a[i] <= a[i+1]))
        a[i] = b[pos] - a[i];
    }

    cout << "YES\n";
    
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