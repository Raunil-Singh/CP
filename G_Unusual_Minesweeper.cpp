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

void preprocessing()
{

    // Code here

}

int par[200000];
int points[200000];

int find(int num)
{
    if(par[num] == num) return num;
    return par[num] = find(par[num]);
}

void unio(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if(pa[points] <= pb[points]) par[pb] = pa;
    else par[pa] = pb;
}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ":\n";
    int n, k;
    cin >> n >> k;

    for(int i = 0 ; i<n ; i++)
        par[i] = i;

    vector<vector<int>> edges(n, vector<int>(3));

    for(int i = 0 ; i<n ; i++) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    sort(all(edges));

    map<int, int> recent_x, recent_y;
    vector<vector<int>> adj(n);
    for(int i = 0 ; i<n ; i++)
    {
        int x = edges[i][0], y = edges[i][1], p = edges[i][2];
        points[i] = p;
        if(recent_x.find(x)!=recent_x.end())
        {
            int prev_y = edges[recent_x[x]][1];
            if(abs(prev_y - y) <= k)
            {
                unio(recent_x[x], i);
            }
        }
        if(recent_y.find(y)!=recent_y.end())
        {
            int prev_x = edges[recent_y[y]][0];
            if(abs(prev_x - x) <= k)
            {
                unio(recent_y[y], i);
            }
        }
        recent_x[x] = i;
        recent_y[y] = i;
    }

    set<int> segs;
    for(int i = 0 ; i<n ; i++) segs.insert(find(i));

    vector<int> time;
    for(int head : segs)
        time.pb(points[head]);
    
    sort(all(time), greater<int>());
    int ans = time.size() - 1;

    // cout << time.size() << "--\n";

    for(int i = 0 ; i<time.size() ; i++)
    {
        // cout << time[i] << " ";
        int curr = max(time[i], i-1);
        ans = min(ans, curr);
        // cout << curr << "**\n";
    }

    cout << ans << "\n";
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

    preprocessing();

    int t;
    cin >> t;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}