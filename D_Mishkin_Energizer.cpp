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
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n == 1)
    {
        cout << "-1\n";
        return;
    }

    vector<int> v;

    char c = s[0];
    int count = 0;
    for(char x : s)
    {
        if(c == x) count++;
        else {
            v.pb(count);
            c = x;
            count = 1;
        }
    }

    v.pb(count);

    if(v.size() == 1)
    {
        cout << "-1\n";
        return;
    }

    cout << 2*n << "\n";
    count = 0;
    for(int i = 0 ; i < v.size()-1 ; i++)
    {
        count += v[i];
        for(int j = 0 ; j < v[i] ; j++)
        {
            cout << count << "\n" << count << "\n";
        }
        count += 2*v[i];
    }

    for(int i = 3*(n - v.back()) ; i<3*n - v.back() ; i++)
    {
        cout << i << "\n";
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