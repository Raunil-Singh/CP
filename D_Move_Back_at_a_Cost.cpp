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
    
    ll n;
    cin >> n;
    deque<ll> dq;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(ll i = 0 ; i < n ; i++)
    {
        ll num;
        cin >> num;
        // cout << "Read " << num << " **\n";
        while(!dq.empty() && dq.back() > num)
        {
            // cout << "moving " << dq.back() << " as " << dq.back() + 1 << " **\n";
            pq.push(dq.back()+1);
            dq.ppb();
        }
        if(!pq.empty() && pq.top() < num)
        {
            // cout << num+1 << " in pq **\n";
            pq.push(num+1);
        }
        else
        {
            // cout << num << " in dq **\n";
            dq.pb(num);
        }
    }

    while(!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";
    
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