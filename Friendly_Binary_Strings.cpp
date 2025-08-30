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
    
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    
    vector<int> ct(3, 0);
    for(int i = 0 ; i<n ; i++)
    {
        if(s1[i] == s2[i] && s1[i] == '0') ct[0]++;
        else if(s1[i] == s2[i] && s1[i] == '1') ct[1]++;
        else ct[2]++;
    }

    if(n&1)
    {
        if(ct[0]%2 == 1 && ct[1]%2 == 1 && ct[2]%2 == 1) cout << "NO\n";
        else cout << "YES\n";
    }
    else
    {
        if(ct[0]%2 == 0 && ct[1]%2 == 0 && ct[2]%2 == 0) cout << "YES\n";
        else cout << "NO\n";
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}