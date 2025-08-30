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
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

void solve(ll tc_no)
{
    
    ll a,b,c;
    cin >> a >> b >> c;

    if(a+1 != c)
    {
        cout << "-1\n";
        return;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(ll i = 0 ; i<c ; i++) pq.push(0);

    for(ll i = 0 ; i<b ; i++)
    {
        ll num = pq.top();
        pq.pop();
        pq.push(num+1);
    }

    for(ll i = 0 ; i<a ; i++)
    {
        pq.pop();
        ll n = pq.top();
        pq.pop();
        pq.push(n + 1);
    }

    cout << pq.top() << "\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
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