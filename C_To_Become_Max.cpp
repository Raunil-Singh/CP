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

void solve(ll tc_no)
{
    
    ll n, k;
    cin >> n >> k;
    vector<int> v(n); inp(v);

    auto valid = [v,n, k](ll h)->bool {
        bool flag = false;
        vector<int> temp; 
        for(ll i = 0 ; i<n-1 ; i++)
        {
            if(v[i] >= h) {flag = true; goto END;}
            if(h-v[i] > k) continue;
            temp = v;
            temp[i] = h;
            ll rem = k-(temp[i]-v[i]);
            for(ll j = i ; j+1<n ; j++)
            {
                if(temp[j+1]>=temp[j]-1) break;
                temp[j+1] = temp[j]-1;
                rem -= (temp[j+1]-v[j+1]);
            }
            if(rem >= 0 && v[n-1] == temp[n-1]) {flag = true; goto END;}
        }
        END:
        // if(flag) for(ll num : temp) cout << num << " ";
        return flag;
    };

    ll l = *max_element(all(v)), r = 1000000000LL;
    while(l+1<r)
    {
        ll mid = (l+r)/2;
        bool flag = valid(mid);
        // cout << l << " " << mid << " " << r << (flag ? " YES\n" : " NO\n");
        if(flag) l = mid;
        else r = mid;
    }

    cout << l << "\n";
    
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