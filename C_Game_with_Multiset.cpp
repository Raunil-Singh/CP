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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll m;
    cin >> m;
    vector<int> v(30, 0);
    
    for(ll i = 0 ; i<m ; i++)
    {
        ll t;
        cin >> t;
        switch(t)
        {
            case 1:
            {
                ll n;
                cin >> n;
                v[n]++;
            }
            break;
            case 2:
            {
                ll n;
                cin >> n;
                vector<int> temp = v;
                ll x = 0;
                for(ll num : temp)
                {
                    ll b = (n&1);
                    n>>=1;
                    // cout << b << " " << num << " " << x << "#\n";
                    if(b && num+x == 0)
                    {
                        cout << "NO\n";
                        goto NEXT_ITR;
                    }
                    x = (x+num-b)/2;
                }
                cout << "YES\n";
            }
            break;
        }
        NEXT_ITR:;
    }
    
    return 0;
}