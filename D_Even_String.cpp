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

#define MOD 998244353

vector<int> invf;

int inv(int a, int m) { // m = MOD
    return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

void preprocessing()
{

    int prod = 1;
    int upper = 500000;
    invf.pb(0);
    for(int i = 1 ; i<=upper ; i++)
    {    
        prod = (prod*inv(i, MOD)) % MOD;
        invf.pb(prod);
    }

}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    
    vector<int> cnts(26); inp(cnts);

    int sum = accumulate(all(cnts), 0LL);

    // cout << sum << "#\n";

    int res = 1;
    for(int i = 1 ; i<=sum ; i++) res = (res*((i+1)/2)) % MOD;

    // cout << res << "$$\n";

    vector<int> dp(sum/2 + 1, 0LL);
    dp[0] = 1;

    for(int &num : cnts)
    {
        if(num == 0LL) continue;
        for(int i = sum/2 ; i >= 0 ; i--)
        {
            dp[i] = (dp[i] * invf[num]) % MOD;
            if(i >= num) dp[i] = (dp[i] + dp[i-num] * invf[num]) % MOD; 
            // cout << dp[i] << " ";
        }
        // cout << "##\n";
    }

    cout << (dp.back()*res) % MOD << "\n";


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