// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

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

vector<int> res;

bool find(int start, int d, int lim, vector<vector<pair<int, int>>> &adj, vector<int>&res, int last)
{
    vector<int> level(last+1, INT_MAX);
    vector<int> parent(last+1, INT_MAX);
    queue<int> q;
    q.push(start);
    level[start] = 0;
    for(int lvl = 0 ; lvl < d ; lvl++)
    {
        int x = q.size();
        while(x--)
        {
            int curr = q.front();
            q.pop();
            for(auto [next, weight] : adj[curr])
            {
                if(weight > lim || level[next] <= lvl+1) continue;
                level[next] = lvl+1;
                parent[next] = curr;
                q.push(next);
            }
        }
    }
    if(level[last] > d) return false;
    res = vector<int>();
    int curr = last;
    while(curr!=INT_MAX)
    {
        res.pb(curr);
        curr = parent[curr];
    }
    return true;
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

    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0 ; i<m ; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].pb(mpr(b, w));
    }

    int l = -1, r = INT_MAX;
    while(l+1 < r)
    {
        int mid = (l+r)/2;
        vector<int> res;
        if(find(0, d, mid, adj, res, n-1)) r = mid;
        else l = mid;
        // cout << l << " " << r << "\n"; 
    }

    if(res.empty()) find(0, d, r, adj, res, n-1);
    if(res.size())
    {
        cout << res.size()-1 << "\n";
        reverse(all(res));
        for(int num : res) cout << num+1 << " ";
        cout << "\n";
    }
    else cout << "-1\n";
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}