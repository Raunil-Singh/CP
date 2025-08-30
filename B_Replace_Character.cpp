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

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> v(26, 0);
    for(char c : s)
        v[c-'a']++;
    ll mini = INT_MAX, maxi = INT_MIN;
    ll a = -1, b = -1;
    for(ll i = 0 ; i<26 ; i++)
    {
        if(v[i] == 0) continue;
        if(mini > v[i])
        {
            mini = v[i];
            a = i;
        }
    }
    for(ll i = 0 ; i<26 ; i++)
    {
        if(v[i] == 0 || a == i) continue;
        if(maxi < v[i])
        {
            maxi = v[i];
            b = i;
        }
    }
    if(b == -1) b = a;
    for(ll i = 0 ; i<n ; i++)
    {
        if(s[i] == 'a' + a)
        {
            s[i] = 'a' + b;
            break;
        }
    }
    cout << s << "\n";
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