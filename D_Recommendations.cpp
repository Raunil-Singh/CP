// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17

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

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;

    vector<pair<int, int>> vp(n);
    for(auto &p : vp) cin >> p.F >> p.S;

    map<pair<int, int>, stack<int>> pos1, pos2;
    for(ll i = 0 ; i<n ; i++)
    {
        pos1[vp[i]].push(i);
        pos2[vp[i]].push(i);
    }

    sort(all(vp), [](pair<int, int> a, pair<int, int> b)->bool {if(a.F == b.F) return a.S > b.S; else return a.F < b.F;});

    vector<int> res(n, 0);
    set<int> rights;
    for(auto p : vp)
    {
        if(pos1[p].size() == 1)
            res[pos1[p].top()] = ((rights.lower_bound(p.S)==rights.end() ? p.S : *rights.lower_bound(p.S)) - p.S);
        // cout << res[pos1[p].top()] << " " << p.F << " " << p.S << "#\n";
        pos1[p].pop();
        rights.insert(p.S);
    }

    sort(all(vp), [](pair<int, int> a, pair<int, int> b)->bool {if(a.S == b.S) return a.F < b.F; else return a.S > b.S;});

    set<int> lefts;
    for(auto p : vp)
    {
        if(pos2[p].size() == 1)
            res[pos2[p].top()] += (p.F+(lefts.lower_bound(-p.F)==lefts.end() ? -p.F : *lefts.lower_bound(-p.F)));
        // cout << res[pos2[p].top()] << " " << p.F << " " << p.S << "#\n";
        pos2[p].pop();
        lefts.insert(-p.F);
    }

    for(ll num : res) cout << num << "\n";
    // cout << "@\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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