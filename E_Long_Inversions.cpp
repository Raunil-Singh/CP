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

bool check(int k, vector<int> &v)
{
    int n = v.size();
    vector<int> x(n, 0);
    int prev = 0;
    for(int i = 0 ; i<n ; i++)
    {
        x[i] ^= prev;
        if(i<=n-k && v[i] ^ x[i] == 0)
        {
            x[i] ^= 1;
            if(i+k < n) x[i+k] ^= 1;
        }
        prev = x[i];
    }

    // for(int &num : x) cout << num << " ";
    // cout << "$$\n";

    for(int i = 0 ; i<n ; i++)
        if(v[i] ^ x[i] != 1) return false;
    return true;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";

    int n;
    cin >> n;
    string s;
    cin >> s;

    set<int> dis;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++)
    {
        v[i] = s[i] - '0';
        dis.insert(v[i]);
    }

    if(dis.size() == 1)
    {
        cout << n << "\n";
        return;
    }
    
    int ans = 0;
    for(int i = 1 ; i<n ; i++)
    {
        if(check(i, v)) ans = i;
        // cout << i << " " << ans << "#\n";
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