// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

const long double eps = 1e-12;

int check(priority_queue<int> pq1, priority_queue<int> pq2, int k)
{
    while(pq1.size() + pq2.size() > k)
    {
        if(pq1.top() < pq2.top()) pq2.pop();
        else pq1.pop();
    }

    ll ans = 0;
    while(!pq1.empty())
    {
        ans+=pq1.top();
        pq1.pop();
    }
    while(!pq2.empty())
    {
        ans+=pq2.top();
        pq2.pop();
    }
    return ans;
}

void solve(ll tc_no)
{
    
    ll n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    vector<int> v(n); inp(v);

    priority_queue<int> pql, pqm, pqr;

    for(ll i = 0 ; i<l ; i++)
    {
        pql.push(v[i]);
        if(pql.size() > r-l+1) pql.pop();
    }
    for(ll i = l ; i<=r ; i++)
    {
        pqm.push(v[i]);
        if(pqm.size() > r-l+1) pqm.pop();
    }
    for(ll i = r+1 ; i<n ; i++)
    {
        pqr.push(v[i]);
        if(pqr.size() > r-l+1) pqr.pop();
    }

    ll ans1 = check(pql, pqm, r-l+1);
    ll ans2 = check(pqm, pqr, r-l+1);
    // cout << ans1 << " " << ans2 << " # ";
    cout << min(ans1, ans2) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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