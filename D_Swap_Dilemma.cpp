// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<int> a(n), b(n);
    inp(a);
    inp(b);

    ll count1 = 0;
    ordered_set os1;
    for(ll i = n-1 ; i>=0 ; i--)
    {
        count1 += os1.order_of_key(a[i]);
        os1.insert(a[i]);
    }

    ll count2 = 0; 
    ordered_set os2;
    for(ll i = n-1 ; i>=0 ; i--)
    {
        count2 += os2.order_of_key(b[i]);
        os2.insert(b[i]); 
    }

    sort(all(a));
    sort(all(b));

    for(ll i = 0 ; i<n ; i++) if(a[i] != b[i]) {cout << "NO\n"; return;}

    if(count1%2 != count2%2) cout << "NO\n";
    else cout << "YES\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
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