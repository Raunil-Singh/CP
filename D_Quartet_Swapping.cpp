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

int dist(vector<int> &v)
{
    int cost = 0;
    ordered_set s;
    for(int num : v)
    {
        cost += (s.size() - (s.order_of_key(num)));
        s.insert(num);
    }
    return cost;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    vector<int> a, b;
    for(int i = 0 ; i<n ; i++)
    {
        if(i%2) b.pb(v[i]);
        else a.pb(v[i]);
    }

    int count = dist(a) + dist(b);

    sort(all(a));
    sort(all(b));

    // cout << count << " # ";

    if(count%2)
    {
        if(n%2) swap(a[a.size()-1], a[a.size()-2]);
        else    swap(b[b.size()-1], b[b.size()-2]);
    }

    vector<int> result;
    for(int i = 0 ; i<n ; i++)
    {
        if(i%2) cout << (b[i/2]) << " ";
        else cout << (a[i/2]) << " ";
    }
    cout << "\n";
    
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