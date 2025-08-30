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
    vector<string> grid(n); inp(grid);
    
    vector<vector<vector<vector<int>>>> 
    dp(n, vector<vector<vector<int>>>       // Row
      (m,vector<vector<int>>                // Col
      (4, vector<int>                       // Dir : 0->up, 1->down, 2->left, 3->right
      (3, 1e11))));                   // Step count when last step at one of the three levels in a given direction at a given cell
    
    int x = 0 , y = 0;

    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<m ; j++)
            if(grid[i][j] == 'S')
            {
                x = i;
                y = j;
                goto OUT;
            }
    OUT:;

    queue<pair<int, vector<int>>> q; // <dist, {row, col, dir, step}>
    vector<int> temp = {x, y, 10, 0};
    q.push(mpr(0LL, temp));

    while(!q.empty())
    {
        // cout << "@\n";
        pair<int, vector<int>> curr = q.front();
        q.pop();
        int dist = curr.F;
        int r = curr.S[0];
        int c = curr.S[1];
        int dir = curr.S[2];
        int lev = curr.S[3];
        // cout << dist << " " << r << " " << c << " " << dir << " " << lev << " #\n";
        for(int i = 0 ; i<4 ; i++)
        {
            int tarl = -1111;
            if(dir == i && lev == 2) continue;
            else if(i != dir) tarl = 0;
            else tarl = (lev+1)%3;
            int a = 0, b = 0;
            switch(i)
            {
                case 0: a = -1; b = 0; break;
                case 1: a = 1; b = 0; break;
                case 2: a = 0; b = -1; break;
                case 3: a = 0; b = 1; break;
            }
            if(grid[r+a][c+b] == '#') continue;
            // cout << dp[r+a][c+b][i][tarl] << " -- " << dist+1 << "$\n";
            if (dp[r+a][c+b][i][tarl] > dist+1)
            {
                dp[r+a][c+b][i][tarl] = dist+1;
                temp = {r+a, c+b, i, tarl};
                q.push(mpr(dp[r+a][c+b][i][tarl], temp));
            }
        }
    }

    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<m ; j++)
            if(grid[i][j] == 'T')
            {
                int min_val = LLONG_MAX;
                for(int k = 0 ; k<4 ; k++)
                    for(int l = 0 ; l<3 ; l++)
                        min_val = min(min_val, dp[i][j][k][l]);
                if(min_val > INT_MAX)
                    cout << "-1\n";
                else cout << min_val << "\n";
                goto END;
            }
    
    END:;

    return 0;
}