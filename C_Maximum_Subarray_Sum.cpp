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
    
    // cout << "Case #" << tc_no << ": ";

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(n); inp(v);

    for(int i = 0 ; i<n ; i++)
        if(s[i] == '0') v[i] = -200000000000;

    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int M = 0;
    int curr = 0;
    for(int i = 0 ; i<n ; i++)
    {
        left[i] = curr;
        curr += v[i];
        if(curr < 0) curr = 0;
        M = max(M, curr);
    }
    curr = 0;
    for(int i = n-1 ; i>=0 ; i--)
    {
        right[i] = curr;
        curr += v[i];
        if(curr < 0) curr = 0;
        M = max(M, curr);
    }

    if(M > k)
    {
        cout << "No\n";
        return;
    }
    if(M == k)
    {
        cout << "Yes\n";
        for(int num : v) cout << num << " ";
        cout << "\n";
        return;
    }

    int pos = 0;
    for(pos = 0; pos<n ; pos++)
        if(s[pos] == '0') break;
    
    if(pos == n)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";

    v[pos] = k - left[pos] - right[pos];

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

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}