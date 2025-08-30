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

    ll n; cin >> n;

    priority_queue<vector<int>> pq;

    for(ll i = 0 ; i<n ; i++)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        pq.push(v);
    }

    map<int,int> m;
    m[INT_MAX] = 0;

    while(!pq.empty())
    {
        vector<int> curr = pq.top(); pq.pop();
        // cout << curr[0] << " " << curr[1] << " " << curr[2] << " ";
        if(m.find(curr[0])==m.end())
            m[curr[0]] = 0;
        m[curr[0]] = max(m[curr[0]], m.lower_bound(curr[1]+1)->second + curr[2]);
        m[curr[0]] = max(m[curr[0]], m.lower_bound(curr[0]+1)->second);
        // cout << m[curr[0]] << " # \n";
    }
    
    cout << (m.lower_bound(0)->second) << "\n";

    return 0;
}