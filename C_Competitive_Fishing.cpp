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
    
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<ll> v(n);
    priority_queue<int> pq;
    
    v[n-1] = (s[n-1]=='1' ? 1 : -1);
    pq.push(v[n-1]);
    
    for(ll i = n-2 ; i>=0 ; i--)
    {
        v[i] = v[i+1] + (s[i]=='1' ? 1 : -1);
        if(i > 0) pq.push(v[i]);
    }

    ll res = 0;
    ll count = 1;

    while((!pq.empty()) && res < k)
    {
        if(pq.top() <= 0)
        {
            pq.pop();
            continue;
        }
        count++;
        res += pq.top();
        pq.pop();
    }

    if(res >= k) cout << count << "\n";
    else cout << "-1\n";
    
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