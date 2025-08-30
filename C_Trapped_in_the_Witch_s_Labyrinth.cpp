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

int dfs(int i, int j, vector<string> &grid, vector<vector<int>> &status, vector<vector<bool>> &visited)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
    if(status[i][j] >= 0) return status[i][j];
    if(visited[i][j]) return status[i][j] = 1;
    visited[i][j] = true;
    int dir_1 = 0 , dir_2 = 0;
    switch(grid[i][j])
    {
        case 'L' : dir_2 = -1; break;
        case 'U' : dir_1 = -1; break;
        case 'R' : dir_2 = 1; break;
        case 'D' : dir_1 = 1; break;
        case '?' : return status[i][j] = 1;
    }
    return status[i][j] = dfs(i+dir_1, j+dir_2, grid, status, visited);
}

void solve(ll tc_no)
{
    
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n); inp(grid);

    vector<vector<int>> status(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(ll i = 0 ; i<n ; i++)
        for(ll j = 0 ; j<m ; j++)
            if(status[i][j] == -1)
                dfs(i, j, grid, status, visited);

    ll ans = 0;
    for(ll i = 0 ; i<n ; i++)
    {
        for(ll j = 0 ; j<m ; j++)
        {
            if(grid[i][j] == '?')
            {
                if((i-1>=0 && status[i-1][j] == 1) ||  (i+1<n && status[i+1][j] == 1) || 
                    (j-1>=0 && status[i][j-1] == 1) ||  (j+1<m && status[i][j+1] == 1))
                    ans++; 
            }
            else ans += status[i][j];
        }
    }

    // for(vector<int> v : status)
    // {
    //     for(ll num : v) cout << num << " " ;
    //     cout << "\n";
    // }

    cout << ans << "\n";    
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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