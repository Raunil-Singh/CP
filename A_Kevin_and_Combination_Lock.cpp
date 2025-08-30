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

    queue<pair<int, bool>> q; // <rem, stat>

    q.push({0, false});
    for(char c : s)
    {
        ll dig = c-'0';
        for(ll i = q.size() ; i>0 ; i--)
        {
            pair<int, bool> p = q.front();
            q.pop();
            if(p.S == true && dig!=3) continue;
            if(dig == 3)
            {
                if(p.S == false)
                    q.push({(p.F*10+dig)%33, false});
                q.push({(p.F*10)%33, !p.S});
            }
            else q.push({(p.F*10+dig)%33, p.S});
        }
    }

    while(!q.empty())
    {
        if(q.front().F == 0 && q.front().S == false)
        {
            cout << "YES\n";
            return;
        }
        q.pop();
    }

    cout << "NO\n";
    
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