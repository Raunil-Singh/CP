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

bool check(vector<string> &s, vector<string> &t, int n, int m, int a, int b)
{
    // cout << "Here!\n";
    for(int i = 0 ; i<m ; i++)
        for(int j = 0 ; j<m ; j++)
            if(s[a+i][b+j] != t[i][j]) return false;
    // cout << "Yay!\n";
    return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, m;
    cin >> n >> m;

    vector<string> s(n), t(m); inp(s); inp(t);

    for(int i = 0 ; i<=n-m ; i++)
    {
        for(int j = 0 ; j<=n-m ; j++)
            if(check(s, t, n, m, i, j))
            {
                cout << i+1 << " " << j+1 << "\n";
                goto out;
            }
        // cout << "What's Wrong??!\n";
    }
    out:;
    
    return 0;
}