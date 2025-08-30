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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void dfs(int i, int j, int pos, string &s, vector<vector<bool>> &seen, int &ans)
{
    if(i<0 || i>6 || j<0 || j>6 || seen[i][j]) return;
    if(i+1 < 7 && j-1 >= 0 && seen[i+1][j-1] && !seen[i][j-1] && !seen[i+1][j]) return;
    if(i+1 < 7 && j+1 < 7 && seen[i+1][j+1] && !seen[i][j+1] && !seen[i+1][j]) return;
    if(i-1 >= 0 && j-1 >= 0 && seen[i-1][j-1] && !seen[i][j-1] && !seen[i-1][j]) return;
    if(i-1 >= 0 && j+1 < 7 && seen[i-1][j+1] && !seen[i][j+1] && !seen[i-1][j]) return;
    if(i>0 && i<6 && j>0 && j<6 && ((!seen[i+1][j] && !seen[i-1][j] && seen[i][j+1] && seen[i][j-1]) || (seen[i+1][j] && seen[i-1][j] && !seen[i][j+1] && !seen[i][j-1]))) return;
    
    if((i == 6 && j == 0) || pos == 48)
    {
        ans += ((i == 6 && j == 0) && pos == 48);
        return;
    }
    seen[i][j] = true;
    if(s[pos] == '?' || s[pos] == 'U') dfs(i-1, j, pos+1, s, seen, ans);
    if(s[pos] == '?' || s[pos] == 'D') dfs(i+1, j, pos+1, s, seen, ans);
    if(s[pos] == '?' || s[pos] == 'R') dfs(i, j+1, pos+1, s, seen, ans);
    if(s[pos] == '?' || s[pos] == 'L') dfs(i, j-1, pos+1, s, seen, ans);
    seen[i][j] = false;
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

    string s = "????????????????????????????????????????????????";
    cin >> s;

    int ans = 0;
    vector<vector<bool>> seen(7, vector<bool>(7, false));
    dfs(0, 0, 0, s, seen, ans);

    cout << ans << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}