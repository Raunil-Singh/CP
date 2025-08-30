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

bool Found(ll res, ll c2, ll c3)
{
    while(c3 >= 0 && res >= 0)
    {
        if(res/2 > c2)
        {
            res -= 6;
            c3--;
        }
        else return true;
    }
    return false;
}

void solve(ll tc_no)
{
    
    string s;
    cin >> s;

    ll sum = 0;
    ll c2 = 0, c3 = 0;

    for(char c : s)
    {
        sum += c-'0';
        if(c == '2') c2++;
        else if(c=='3') c3++;
    }

    ll ex = (sum%9);

    vector<int> target = {0, 8, 16, 6, 14, 4, 12, 2, 10};

    ll res = target[ex];

    cout << (Found(res, c2, c3) ? "YES" : "NO") << "\n";
    
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