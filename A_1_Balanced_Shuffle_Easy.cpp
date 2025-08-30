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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> pref(n);
    pref[0] = mpr(0, 0);
    for(int i = 1 ; i<n ; i++)
        pref[i] = mpr(pref[i-1].F + (s[i-1]=='(' ? 1 : -1), -i);

    sort(all(pref));

    for(int i = 0 ; i<n ; i++)
    {
        cout << pref[i].F << " " << s[-pref[i].S] << "\n";
    }
    // cout << "\n";
    
    
    return 0;
}