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

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> v(n, vector<int>(20, -2));
    for(int i = 1 ; i<n ; i++)
    {
        cin >> v[i][0];
        v[i][0]--;
    }

    for(int i = 1 ; i<20 ; i++)
        for(int j = 0 ; j<n ; j++)
            if(v[j][i-1] != -2) v[j][i] = v[v[j][i-1]][i-1];
    
    while(q--)
    {
        int x, k;
        cin >> x >> k;
        int curr = x-1;
        for(int i = 0 ; i<20 && curr != -2 ; i++)
            if(k & (1<<i)) curr = v[curr][i];

        cout << curr + 1 << "\n";
    }
    
    return 0;
}