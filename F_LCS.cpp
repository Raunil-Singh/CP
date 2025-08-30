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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    string s[2];
    cin >> s[0] >> s[1];

    vector<vector<int>> dp(s[0].length(), vector<int>(s[1].length()));
    for(ll i = 0 ; i<s[0].length() ; i++)
    {
        for(ll j = 0 ; j<s[1].length() ; j++)
        {
            ll n1 = i==0? 0 : dp[i-1][j];
            ll n2 = j==0? 0 : dp[i][j-1];

            dp[i][j] = max(n1, n2);

            if(s[0][i] == s[1][j])
                dp[i][j] = max(dp[i][j], (i==0 || j==0 ? 0 : dp[i-1][j-1])+1);
        }
    }

    string res = "";

    ll i = s[0].length()-1, j = s[1].length()-1;
    while(i>=0 && j>=0)
    {
        if(s[0][i] == s[1][j] && (i == 0 || j == 0 || dp[i-1][j-1]+1 == dp[i][j]))
        {
            res.pb(s[0][i]);
            i--;
            j--;
            continue;
        }
        else
        {
            ll n1 = i==0? 0 : dp[i-1][j];
            ll n2 = j==0? 0 : dp[i][j-1];
            if(n1 >= n2) i--;
            else j--;
        }
    }

    reverse(all(res));

    cout << res << "\n";
    
    return 0;
}