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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v(n); inp(v);

    vector<int> va(n+1, 0);
    for(int i = 0 ; i<n ; i++)
    {
        if(v[i] < a) va[i+1] = 1;
        else if(v[i] > a) va[i+1] = -1;
        va[i+1] += va[i];
    }
    
    vector<int> vb(n+1, 0);
    for(int i = 0 ; i<n ; i++)
    {
        if(v[i] < b) vb[i+1] = 1;
        else if(v[i] > b) vb[i+1] = -1;
        vb[i+1] += vb[i];
    }

    // for(int &num : va) cout << num << " ";
    // cout << "\n";
    // for(int &num : vb) cout << num << " ";
    // cout << "\n";

    int ans = 0;
    for(int i = 1 ; i<=n+1 ; i++)
    {
        for(int j = 1 ; j<=n+1 ; j++)
        {
            if(i <= j)
            {
                int sa = va[i-1];
                int sb = vb[j-1];
                if(a < b) sb++;
                else if(a > b) sb--;
                if(sa > sb) 
                {
                    ans++;
                }
            }
            if(i >= j)
            {
                int sa = va[i-1];
                int sb = vb[j-1];
                if(b > a) sa--;
                else if(b < a) sa++;
                if(sa > sb) 
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}