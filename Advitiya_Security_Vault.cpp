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

#define MOD 1000000007

void solve(ll tc_no)
{
    ll n, k;
    cin >> n >> k;
    
    vector<int> v(n); inp(v);
    
    int ans = 1;
    for(int num : v)
        if(num == 0) ans = (ans*k) % MOD;
    
    int zc = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(v[i] == 0) v[i] = v[n-i-1];
        else if(v[n-i-1] && v[i]!=v[n-i-1])
        {
            cout << ans << "\n";
            return;
        }
        if(v[i] == 0) zc++;
    }
    
    for(int num : v) cout << num << " ";
    cout << "#\n";
    
    if((n&1) && v[n/2] == 0) zc--;
    
    int temp = (zc>0 ? 1 : 0);
    
    for(int i = 0 ; i<n-i-1 ; i++)
    {
        if(!v[i] && !v[n-i-1])
        {
            int x = (k*(k-1)/2) % MOD;
            temp = (temp*x) % MOD;
        }
    }
    
    if((n&1) && v[n/2] == 0) temp = (temp*k) % MOD;
    
    cout << (ans - temp + MOD) % MOD << "\n";
    
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