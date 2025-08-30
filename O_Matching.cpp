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

    ll n;
    cin >> n;
    vector<int> frame(n, 0);
    for(ll i = 0 ; i<n ; i++)
    {
        vector<ll> v(n); inp(v);
        for(ll j = n-1 ; j>=0 ; j--)
            frame[i] = frame[i]*2 + v[j];
    }

    ll mask_count = 1<<n;

    vector<vector<int>> dp(n, vector<int>(mask_count, 0));
    for(ll mask = 0 ; mask < mask_count ; mask++)
        dp[0][mask] = __popcount(mask&frame[0]);
    
    for(ll level = 1 ; level<n ; level++)
    {
        for(ll mask = 0 ; mask<mask_count ; mask++)
        {
            if(__popcount(mask) != level+1) continue; // To only deal with necessary cases and avoid unnecessary computation
            ll temp = mask&frame[level];
            for(ll b = 1 ; b<=mask_count ; b<<=1)
                if(temp&b) dp[level][mask] = (dp[level][mask]+dp[level-1][mask^b]) % MOD;
        }
    }

    cout << dp[n-1][mask_count-1] << "\n";

    return 0;
}