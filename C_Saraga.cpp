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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> c1(26, INT_MAX), c2(26, INT_MAX);
    for(ll i = 1 ; i<s1.length() ; i++)
        c1[s1[i]-'a'] = min(c1[s1[i]-'a'], i);
    for(ll i = s2.length()-2 ; i>=0 ; i--)
        c2[s2[i]-'a'] = min(c2[s2[i]-'a'], (int)s2.length()-i);
    
    ll min_char = 0;
    for(ll i = 0 ; i<26 ; i++)
        if(c1[min_char] + c2[min_char] > c1[i] + c2[i]) min_char = i;
    
    if(c1[min_char] == INT_MAX || c2[min_char] == INT_MAX)
    {
        cout << "-1\n";
        return 0;
    }
    
    for(ll i = 0 ; i<c1[min_char] ; i++) cout << s1[i];
    for(ll i = s2.length() - c2[min_char] ; i<s2.length() ; i++) cout << s2[i];
    cout << "\n";
    
    return 0;
}