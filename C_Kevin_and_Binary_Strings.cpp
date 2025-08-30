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
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]

void solve(ll tc_no)
{
    
    string s;
    cin >> s;
    ll n = s.length();
    
    cout << "1 " << n << " ";

    ll pos = -1;
    for(ll i = 0 ; i<n ; i++)
        if(s[i] == '0')
        {
            pos = i;
            break;
        }
    
    if(pos == -1)
    {
        cout << "1 1\n";
        return;
    }

    string target = "";
    for(ll i = pos ; i<n ; i++)
        target.pb(s[i]=='1' ? '0' : '1');

    // cout << target << " # ";

    ll ans = pos;
    vector<int> best(n-pos, false);
    for(ll i = 0; i<pos ; i++)
    {
        vector<int> temp;
        bool flag = true;
        for(ll j = i ; j-i<n-pos ; j++)
        {
            bool curr = (target[j-i] == s[j]);
            temp.pb(curr);
            if(curr == true && best[j-i]==false && flag)
                ans = i;
            else if(curr == false && best[j-i]==true && flag)
                flag = false;
        }
        if(ans == i)
        {
            best = temp;
        }
    }

    cout << ans+1 << " " << ans+n-pos << "\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}