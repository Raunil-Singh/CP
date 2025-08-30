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

#define MOD 1000000007

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, k;
    cin >> n >> k;
    vector<int> a(n);  inp(a);

    vector<int> old(k+1, 0);
    for(ll i = 0 ; i<=k ; i++) old[i] = (a[n-1] >= i ? 1 : 0);

    for(ll i = n-2 ; i>=0 ; i--)
    {
        vector<int> present(k+1);
        for(ll t = 1 ; t<=k ; t++) old[t] = (old[t]+old[t-1]) % MOD;
        for(ll j = 0 ; j<=k ; j++)
        {
            if(j<=a[i]) present[j] = old[j];
            else present[j] = (old[j] - old[j-a[i]-1] + MOD) % MOD;
        }
        old = present;
    }

    cout << old.back() << "\n";
    
    return 0;
}