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

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;

    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for(int i = 1 ; i<n ; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }

    vector<int> color(n); inp(color);

    queue<int> q;
    for(int i = 0 ; i<n ; i++)
    {
        if(deg[i] == 1) q.push(i);
    }

    vector<bool> seen(n);

    int last = -1;
    while(!q.empty())
    {
        int curr = q.front();
        // cout << curr+1 << " " << deg[curr] << " $\n";
        q.pop();
        if(seen[curr]) continue;
        last = curr;
        seen[curr] = true;
        int next = -1;
        for(int neighbor : adj[curr])
        {
            if(seen[neighbor]) continue;
            next = neighbor;
            break;
        }
        if(next!=-1 && color[next] == color[curr])
        {
            deg[next]--;
            if(deg[next] == 1) q.push(next);
        }
    }

    int count = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(!seen[i])
        {
            // cout << "#" << i << "\n";
            count++;
        }
    }

    if(count > 1) cout << "NO\n";
    else {
        for(int i = 0 ; i<n ; i++) if(!seen[i]) last = i;
        cout << "YES\n" << last+1 << "\n";
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}