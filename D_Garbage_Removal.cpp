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

int clear_trash(vector<set<int>> &x, vector<set<int>> &y, int row)
{
    int res = x[row].size();
    for(int num : x[row])
        y[num].erase(row);
    x[row].clear();
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int h, w, n;
    cin >> h >> w >> n;

    vector<set<int>> x(h+1);
    vector<set<int>> y(w+1);

    for(int i = 0 ; i<n ; i++)
    {
        int a, b;
        cin >> a >> b;
        x[a].insert(b);
        y[b].insert(a);
    }

    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(a == 1) cout << clear_trash(x, y, b) << "\n";
        else cout << clear_trash(y, x, b) << "\n";
    }
    
    return 0;
}