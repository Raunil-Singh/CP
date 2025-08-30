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
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n); inp(v);

    if(k == 1)
    {

        int lar = *max_element(all(v));
        
        if(lar == v[0]) cout << (*max_element(v.begin() + 1, v.end()) + lar) << "\n";
        else if(lar == v[n-1]) cout << (*max_element(v.begin(), v.begin() + n - 1) + lar) << "\n";
        else cout << max(v[0], v[n-1]) + lar << "\n";

        return;
    }

    int ans = 0;
    for(int i = 0 ; i<n ; i++)
    {
        int curr = v[i];
        int picked = 0;
        priority_queue<int> pq1;
        for(int j = 0 ; j<i ; j++) pq1.push(v[j]);
        priority_queue<int> pq2;
        for(int j = i+1 ; j<n ; j++) pq2.push(v[j]);

        while(picked < k)
        {
            if(pq1.size() == 0 || (pq2.size() > 0 && pq1.top() < pq2.top()))
            {
                curr += pq2.top();
                pq2.pop();
            }
            else
            {
                curr += pq1.top();
                pq1.pop();
            }
            picked++;
        }

        ans = max(ans, curr);
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}