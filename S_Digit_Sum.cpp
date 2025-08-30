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

    string k;
    cin >> k;
    ll n = (ll)(k.length());

    int d;
    cin >> d;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(10, vector<int>(d, 0)));
    for(ll i = 0 ; i<10 ; i++)
        dp[0][i][i%d] += 1;
    
    for(ll pos = 1 ; pos < n ; pos++)
        for(ll dig = 0 ; dig<=9 ; dig++)
            for(ll x = 0 ; x<d ; x++)
                for(ll i = 0 ; i<=9 ; i++)
                    dp[pos][dig][x] = (dp[pos][dig][x]+dp[pos-1][i][(x-dig+10*d) % d]) % MOD;

    ll ans = -1;
    ll tar = 0;
    for(ll pos = 0 ; pos<n ; pos++)
    {
        ll curr_d = k[pos]-'0';
        for(ll dig = 0 ; dig<curr_d ; dig++)
            ans = (ans + dp[n-pos-1][dig][tar]) % MOD;
        tar = (tar-curr_d + 10*d) % d;
    }

    ll rem = 0;
    for(char dig : k)
        rem = (rem+dig-'0') % d;
    
    if(rem == 0) ans = (ans+1) % MOD;

    // for(ll pos = 0 ; pos<n ; pos++)
    // {
    //     for(ll dig = 0 ; dig<=9 ; dig++)
    //     {
    //         for(ll l = 0 ; l<d ; l++)
    //             cout << dp[pos][dig][l] << " ";
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    cout << ans << "\n";
    
    return 0;
}