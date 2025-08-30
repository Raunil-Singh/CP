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
// use less_equal for multiple entries

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

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void solve(ll tc_no)
{
    
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(auto &p : v) cin >> p.F >> p.S;

    priority_queue<pair<int, int>> w;
    priority_queue<pair<int, int>> h;

    map<int, pair<int, int>> mapping;

    int area = 0;

    for(int i = 0 ; i<n ; i++)
    {
        mapping[i+1] = v[i];
        w.push(mpr(v[i].F, i+1));
        h.push(mpr(v[i].S, i+1));
        area += v[i].F*v[i].S;
    }

    set<int> seen;
    
    int ans = 0;
    if(area % w.top().F == 0)
    {
        int flag = 0;
        vector<int> dims = {area/w.top().F, w.top().F};
        int curr = 0;
        while((curr && h.size() > 0) || (!curr && w.size() > 0))
        {
            int target = (curr ? h.top().F : w.top().F);
            while(curr && h.top().F == target)
            {
                if(seen.find(h.top().S)!=seen.end()) h.pop();
                else
                {
                    seen.insert(h.top().S);
                    dims[1] -= mapping[h.top().S].S;
                    h.pop();
                }
            }
            while(!curr && w.top().F == target)
            {
                if(seen.find(w.top().S)!=seen.end()) w.pop();
                else
                {
                    seen.insert(w.top().S);
                    dims[0] -= mapping[w.top().S].F;
                    w.pop();
                }
            }

            curr = (curr+1) & 1LL;
        }
        
    }

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