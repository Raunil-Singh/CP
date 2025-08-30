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
    
    ll n;
    cin >> n;
    vector<int> v(n); inp(v);

    ll div_pos = 0;
    while(div_pos<n && abs(v[div_pos])==1ll) div_pos++;

    ll min_a = 0, max_a = 0;
    ll curr_1 = 0, curr_2 = 0;
    for(ll i = 0 ; i<div_pos ; i++)
    {
        curr_1 += v[i];
        if(curr_1 < min_a) min_a = curr_1;
        if(curr_1 > 0) curr_1 = 0;
        curr_2 += v[i];
        if(curr_2 > max_a) max_a = curr_2;
        if(curr_2 < 0) curr_2 = 0;
    }

    // cout << min_a << " " << max_a << " # "; 

    ll min_b = 0, max_b = 0;
    curr_1 = 0, curr_2 = 0;
    for(ll i = div_pos+1 ; i<n ; i++)
    {
        curr_1 += v[i];
        if(curr_1 < min_b) min_b = curr_1;
        if(curr_1 > 0) curr_1 = 0;
        curr_2 += v[i];
        if(curr_2 > max_b) max_b = curr_2;
        if(curr_2 < 0) curr_2 = 0;
    }

    
    // cout << min_b << " " << max_b << " # ";

    set<int> ans;
    for(ll i = min(min_a, min_b) ; i<=max(max_a, max_b) ; i++) ans.insert(i);

    // cout << ans.size() << " # \n";
    // for(ll num : ans) cout << num << " ";
    // cout << "#\n";

    min_a = 0, min_b = 0, max_a = 0, max_b = 0;
    ll curr = 0;
    for(ll i = div_pos-1 ; i>=0 ; i--)
    {
        curr += v[i];
        min_a = min(curr, min_a);
        max_a = max(curr, max_a);
    }
    curr = 0;
    for(ll i = div_pos+1 ; i<n ; i++)
    {
        curr += v[i];
        min_b = min(curr, min_b);
        max_b = max(curr, max_b);
    }

    if(div_pos<n)
    {
        ll mini = min_a+min_b, maxi = max_a+max_b;
        // cout << mini << " " << maxi << " # ";
        for(ll i = mini ; i<=maxi ; i++) ans.insert(i+v[div_pos]);
    }
    cout << ans.size() << "\n";
    for(ll num : ans) cout << num << " ";
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

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}