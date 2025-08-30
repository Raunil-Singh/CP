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
    
    vector<int> pos;
    vector<int> num;
    pos.pb(0);
    num.pb(0);

    int n, q;
    cin >> n >> q;

    int next = 0;
    for(int i = 0 ; i<n ; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a == 1)
        {
            next++;
            pos.pb(next);
            num.pb(b);
        }
        else next *= b+1;
    }

    for(int k : pos) cout << k << " ";
    cout << "#\n";
    for(int k : num) cout << k << " ";
    cout << "#\n";
    

    for(int i = 0 ; i<q ; i++)
    {
        int p; cin >> p;
        int l, r; 
        // AGAIN:
        // l = 0;
        // r = pos.size();
        // while(l+1<r)
        // {
        //     int m = l + (r-l)/2;
        //     if(pos[m] <= p) l = m;
        //     else r = m; 
        // }
        // if(p == pos[l]) cout << num[l] << " ";
        // // cout << p << " " << pos[r] << "#\n";
        // else
        // {
        //     p %= pos[l];
        //     goto AGAIN;
        // }
    }

    cout << "\n";
    
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