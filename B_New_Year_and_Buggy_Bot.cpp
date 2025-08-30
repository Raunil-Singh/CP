#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

#define int long long // upto 9.2 * (10^18)
#define uint unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

int dfs(int x, int y, vector<string> &v, string &s, string &dir, int ind)
{
    // cout << x << " " << y << "\n";
    if(x < 0 || x >= v.size() || y < 0 || y >= v[0].size()) return 0;
    if(v[x][y] == '#') return 0;
    if(v[x][y] == 'E') return 1;
    if(ind == s.size()) return 0;
    switch(dir[s[ind] - '0'])
    {
        case 'E' : return dfs(x, y+1, v, s, dir, ind+1);
        case 'W' : return dfs(x, y-1, v, s, dir, ind+1);
        case 'N' : return dfs(x+1, y, v, s, dir, ind+1);
        case 'S' : return dfs(x-1, y, v, s, dir, ind+1);
    }
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, m;
    cin >> n >> m;

    vector<string> v(n); inp(v);

    string s; cin >> s;

    int x = 0, y = 0;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(v[i][j] == 'S')
            {
                x = i;
                y = j;
                goto OUT;
            }
        }
    }
    OUT:;

    int count = 0;
    string dir = "ENSW";
    for(int i = 0 ; i<24 ; i++)
    {
        count += dfs(x, y, v, s, dir, 0);
        next_permutation(all(dir));
        // cout << count << " " << dir << "\n";
    }

    cout << count << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}