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

    ll n, q;
    cin >> n >> q;

    vector<int> a(q);
    vector<int> b(q);

    vector<int> len(n, 1);

    for(ll i = 0 ; i<q ; i++)
    {
        ll num;
        char c;
        cin >> num >> c;
        a[i] = num-1;
        b[i] = (c=='+' ? 1 : -1);
        if(b[i]==1)
        len[a[i]] += b[i];
    }

    vector<vector<int>> dp1(n, vector<int>(n));

    for(ll i = 0 ; i<n ; i++)
    {
        for(ll j = 0 ; j<n ; j++)
        {
            ll temp=0;
            ll dist = 0;
            if(i == j)
            {
                dist = INT_MAX;
                goto NEXT;
            }
            for(ll k = 0 ; k<q ; k++)
            {
                if(a[k] == i && b[k] == 1) temp++;
                if(a[k] == j && b[k] == -1) temp--;
                dist = max(dist, temp);
            }
            NEXT:;
            dp1[i][j] = dist;
        }
    }

    ll mask_count = 1<<n;    
    vector<vector<int>> dp2(mask_count, vector<int>(n, INT_MAX));

    ll ans = 0;
    
    for(ll i = 0 ; i<n ; i++) dp2[1<<i][i] = len[i];

    for(ll mask = 1 ; mask<mask_count ; mask++)
    {
        ans = INT_MAX;

        for(ll i = 0 ; i<n ; i++)
        {
            if(!(mask&(1<<i))) continue;
            ll prev = mask - (1<<i);
            for(ll j = 0 ; j<n ; j++)
            {
                if(!(prev&(1<<j))) continue;
                dp2[mask][i] = min(dp2[prev][j] + dp1[j][i] + len[i] - len[j] + 1, dp2[mask][i]);
            }
            ans = min(ans, dp2[mask][i]);
        }

        // log2() takes a lot of time! Avoid using it!
        // ll temp = mask;
        // while(temp > 0)
        // {
        //     ll pos = (int)(log2((temp^(temp-1))+1))-1;
        //     ll prev = mask-(1<<pos);
        //     ll temp2 = prev;
        //     while(temp2 > 0)
        //     {
        //         ll pos2 = (int)(log2((temp2^(temp2-1))+1))-1;
        //         dp2[mask][pos] = min(dp2[prev][pos2] + dp1[pos2][pos] + len[pos] - len[pos2] + 1, dp2[mask][pos]);
        //         temp2 = temp2&(temp2-1);
        //     }
        //     ans = min(dp2[mask][pos], ans);
        //     temp = temp&(temp-1);
        // }
    }

    cout << ans << "\n";

    return 0;
}