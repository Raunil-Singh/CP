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
    
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    int a1 = -1, a2 = -1;
    int p1 = x, p2 = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(s[i] == 'R')
        {
            p1++;
            p2++;
        }
        else
        {
            p1--;
            p2--;
        }
        if(a1 == -1 && p1 == 0) a1 = i+1;
        if(a2 == -1 && p2 == 0) a2 = i+1;
    } 

    // cout << a1 << " " << a2 << "#\n";

    if(a1 == -1 || a1 > k)
    {
        cout << "0\n";
        return;
    }

    if(a2 == -1) cout << "1\n";
    else cout << 1 + (k-a1)/a2 << "\n";
    
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