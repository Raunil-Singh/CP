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

void preprocessing()
{

    // Code here

}

void solve(ll tc_no)
{
    
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> vp(n);
    for(pair<int, int> &p : vp) cin >> p.S >> p.F;

    sort(all(vp), greater<pair<int, int>>());

    bool flag = false;
    for(int i = 0 ; i<n && !flag ; i++)
        if(vp[i].S <= l) flag = true;

    if(!flag)
    {
        cout << 0 << "\n";
        return;
    }

    int ans = 1;

    for(int i = 0 ; i<n ; i++)
    {
        priority_queue<int> pq1;

        int sum = 0;
        int prev = 0;

        // cout << "Starting from index " << i << "##\n";

        for(int j = i ; j<n ; j++)
        {
            pq1.push(vp[j].S);
            int diff = vp[i].F - vp[j].F;
            
            sum += diff - prev + vp[j].S;

            while(sum > l && !pq1.empty())
            {
                // cout << "Removed " << pq1.top() << " !\n"; 
                sum -= pq1.top();
                pq1.pop();
            }

            ans = max(ans, (int)pq1.size());

            prev = diff;
        }
    }

    cout << ans << "\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}