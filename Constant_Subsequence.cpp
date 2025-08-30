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

bool check(int tar, vector<int>&pos, vector<int>&neg)
{
    ll curr = 0;
    ll i1 = 0, i2 = 0;
    while(i1 < pos.size() && i2 < neg.size())
    {
        if(curr + pos[i1] <= tar)
        {
            curr += pos[i1];
            i1++;
        }
        else
        {
            curr += neg[i2];
            i2++;
        }
        curr = max(curr, 0LL);
        // cout << i1 << " " << i2 << "\n";
    }
    if(i2 == neg.size())
    {
        while(i1<pos.size())
        {
            curr += pos[i1];
            i1++;
        }
    }
    return curr <= tar;
}

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<int> v(n); inp(v);
    
    vector<int> pos, neg;
    for(ll num : v)
    {
        if(num > 0) pos.pb(num);
        else if(num < 0) neg.pb(num);
    }
    
    ll l = -1, r = (pos.size()>0 ? accumulate(all(pos), 0LL) : 0);
    while(l+1<r)
    {
        ll tar = (l+r)/2;
        // cout << tar << "#\n";
        if(check(tar, pos, neg)) r = tar;
        else l = tar;
    }
    
    cout << r << "\n";
    
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