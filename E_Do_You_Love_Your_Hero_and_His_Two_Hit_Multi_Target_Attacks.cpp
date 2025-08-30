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

void solve(ll tc_no)
{
    
    int k;
    cin >> k;

    vector<int> counts;

    while(k>0)
    {
        int l = 0, r = 500;
        while(l+1<r)
        {
            int m = (l+r)/2;
            if(m*(m-1)/2 <= k) l = m;
            else r = m;
        }
        counts.pb(l);
        k -= l*(l-1)/2;
    }

    cout << accumulate(all(counts), 0LL)+1 << "\n";
    int last = 0;
    cout << "-1 -1" << "\n";
    for(int i = 0 ; i<counts.size() ; i++)
    {
        for(int j = 0 ; j<counts[i] ; j++)
        {
            cout << i << " " << last << "\n";
            last++;
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