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

bool check(vector<int> &v, int tar, int k)
{
    if(tar * k > v.size()) return false;
    vector<vector<int>> mat(k, vector<int>(tar, -1));
    int curr = k-1;
    int unseen = tar;
    for(int &num : v)
    {
        if(num >= tar) continue;
        if(mat[curr][num] == -1) unseen--;
        if(unseen == 0)
        {
            curr--;
            if(curr < 0) return true;
            unseen = tar;
        }
        else mat[curr][num] = 1;
    }
    return false;
}

void solve(ll tc_no)
{
    // cout << ".........\n";
    int n, k;
    cin >> n >> k;
    vector<int> v(n); inp(v);

    int l = 0, r = n+2;
    while(l+1<r)
    {
        int m = (l+r)/2;
        if(check(v, m, k)) l = m;
        else r = m;
    }
    // cout << "\n\nResult : ";
    cout << l << "\n";
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