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

int recursion(vector<vector<int>>&v, int l, int r, int t, int b)
{
    if(l==r && t==b)
    {
        v[t][l] = 0;
        return 1;
    }
    if((r - l + 1)&1)
    {
        int curr = recursion(v, l+1, r, t+1, b);
        for(int i = l+1 ; i<=r ; i++)
        {
            v[t][i] = curr;
            curr++;
        }
        for(int i = t ; i<=b ; i++)
        {
            v[i][l] = curr;
            curr++;
        }
        return curr;
    }
    else
    {
        int curr = recursion(v, l, r-1, t, b-1);
        for(int i = t ; i<b ; i++)
        {
            v[i][r] = curr;
            curr++;
        }
        for(int i = l ; i<=r ; i++)
        {
            v[b][i] = curr;
            curr++;
        }
        return curr;
    }
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;

    vector<vector<int>> res(n, vector<int>(n));
    recursion(res, 0, n-1, 0, n-1);
    for(vector<int> v : res)
    {
        for(int num : v) cout << num << " ";
        cout << "\n";
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

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}