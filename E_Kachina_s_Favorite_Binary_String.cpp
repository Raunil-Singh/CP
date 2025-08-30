// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17

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

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;

    cout << "? 1 " << n << "\n";
    ll resp;
    cin >> resp;
    if(resp == 0)
    {
        cout << "! IMPOSSIBLE\n";
        return;
    }

    string s = "1";
    ll prev = 0;
    for(ll i = 2 ; i<=n ; i++)
    {
        cout << "? 1 " << i << "\n";
        int resp; cin >> resp;
        if(resp == prev)
        {
            if(prev == 0) s.pb('1');
            else
                s.pb('0');
        }
        else
        {
            if(prev == 0)
            {
                ll len = s.length();
                for(ll i = 1 ; i<=resp ; i++)
                    s[len-i] = '0';
            }
            s.pb('1');
        }
        prev = resp;
    }

    cout << "! " << s << "\n";
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

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