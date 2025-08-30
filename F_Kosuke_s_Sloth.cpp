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

void solve(ll tc_no)
{
    
    ull n, k;
    cin >> n >> k;

    if(k == 1)
    {
        cout << n%MOD << "\n";
        return;
    }

    map<ull, ull> m;
    m[0] = 0;

    ull a = 1, b = 1;
    ull num = 1;
    ull count = 0;
    while(true)
    {
        num++;
        b += a;
        a = b-a;
        b %= k;
        if(a==0)
        {
            count++;
            m[count] = num;
            if(b==1) goto OUT;
        }
    }
    OUT:;

    ull ans = (m[count]*((n/count)%MOD))%MOD;
    ans = (ans + m[n%count]) % MOD;
    cout << ans << "\n";

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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