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

    ll n, s;
    cin >> n >> s;

    vector<int> v(n); inp(n, v);

    ll sum = accumulate(v.begin(), v.end(), (ll)0);
    ll tar = s % sum;
    
    set<int> pre;
    int curr = 0;
    pre.insert(curr);

    for(ll num : v)
    {
        curr += num;
        if(pre.find(curr-tar) != pre.end() || (s>=sum && pre.find(curr-(sum-tar)) != pre.end()))
        {
            cout << "Yes\n";
            return 0;
        }
        else pre.insert(curr);
    }

    cout << "No\n";

    return 0;
}