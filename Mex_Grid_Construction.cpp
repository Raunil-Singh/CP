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

void insertion(priority_queue<int> &a, priority_queue<int, vector<int>, greater<int>> &b, int num)
{
    if(num == a.top()+1)
    {
        a.push(num);
        while(!b.empty() && b.top() == a.top()+1)
        {
            a.push(b.top());
            b.pop();
        }
    }
    else b.push(num);
}

void solve(vector<vector<int>>&grid, int x, int y)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    set<int> s;
    maxHeap.push(-1);
    for(int i = 0 ; i<x ; i++) insertion(maxHeap, minHeap, grid[i][y]);
    for(int i = 0 ; i<y ; i++) insertion(maxHeap, minHeap, grid[x][i]);

    grid[x][y] = maxHeap.top() + 1;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            solve(grid, i, j);
        }
    }

    for(vector<int> &v : grid)
    {
        for(int x : v) cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}