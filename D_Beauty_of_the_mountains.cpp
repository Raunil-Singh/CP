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

void solve(ll tc_no)
{

    // cout << "Test no: " << tc_no << " : ";
    
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for(vector<int> &temp : v) inp(temp);
    vector<string> mat(n); inp(mat);

    // cout << "INPUT DONE\n";

    int b = 0;
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<m ; j++)
            if(mat[i][j] == '0') b -= v[i][j];
            else b += v[i][j];

    b = abs(b);

    // cout << "PROCESSING OF b IS DONE\n" << "b = " << b << "\n";
        
    vector<vector<int>> counts(n+1, vector<int>(m+1, 0));
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<m ; j++) counts[i+1][j+1] = (mat[i][j] == '1' ? 1 : -1);
    
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<m ; j++) counts[i+1][j+1] += counts[i][j+1];
    
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<m ; j++) counts[i+1][j+1] += counts[i+1][j];
    
    int x = abs(counts[k][k] - counts[k][0] - counts[0][k] + counts[0][0]);

    for(int i = 0 ; i+k<=n ; i++)
        for(int j = 0 ; j+k<=m ; j++)
            x = gcd(x, abs(counts[k+i][k+j] - counts[k+i][j] - counts[i][k+j] + counts[i][j]));
    
    cout << ((b==0 && x == 0) || (x!=0 && b%x == 0) ? "YES\n" : "NO\n");
    

}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}