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

bool check(int a, int b)
{
    cout << "? " << a << " " << b << "\n";
    string s;
    cin >> s;
    return s[0] == 'Y';
}

void ms(vector<int>&v, int l, int r)
{
    if(l>=r) return;
    int m = (l+r)/2;
    ms(v, l, m);
    ms(v, m+1, r);
    vector<int> temp;
    int a = l, b = m+1;
    while(a<=m || b<=r)
    {
        if(b>r || (a<=m && check(v[a], v[b])))
        {
            temp.pb(v[a]);
            a++;
        }
        else
        {
            temp.pb(v[b]);
            b++;
        }
    }
    for(int i = l ; i<=r ; i++) v[i] = temp[i-l];
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++) v[i] = i+1;

    ms(v, 0, n-1);

    vector<int> res(n);
    for(int i = 0 ; i<n ; i++)
    {
        res[v[i]-1] = i+1;
    }

    cout << "! ";
    for(int num : res) cout << num << " ";
    cout << "\n";
    
    return 0;
}