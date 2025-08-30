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
    
    int n, k;
    cin >> n >> k;
    vector<int> v;
    vector<int> vals;

    int temp = k;
    int num = 1;
    while(temp)
    {
        if(temp&1) vals.pb(num);
        num <<= 1;
        temp >>= 1;
    }

    int cap = (1<<(vals.size())) - 1;

    // cout << vals.size() << "\n";
    // cout << cap << "\n";
    // for(int num : vals) cout << num << " ";
    // cout << "#\n";

    for(int i = 0 ; i<=cap && i<n ; i++)
    {
        num = 0;

        for(int j = 0 ; j<vals.size() ; j++)
            if(i & (1<<j)) num += vals[j];

        v.pb(num);
    }

    while(v.size() < n) v.pb(k);

    int bor = 0;
    for(int num : v) bor |= num;
    if(bor != k)
    {
        v.ppb();
        v.pb(k);
    }

    for(int num : v) cout << num << " ";
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