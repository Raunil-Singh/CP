// 10-06-2025 21:30:45 (IST +0530)
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

void preprocessing()
{

    // Code here

}

void dijkstra_all_pair(string &s, vector<vector<pair<int, int>>>&adj, vector<vector<int>>&dist, int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
            dist[i][j] = INT_MAX*10000LL;
        if(s[i] == '.')
            dist[i][i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(mpr(s[i] == 'x' ? INT_MAX*10000LL : 0, i));
        while(!pq.empty())
        {
            auto [net, u] = pq.top();
            pq.pop();
            if(dist[i][u] < net) continue;
            for(auto [v, w] : adj[u])
            {
                if(s[v] == 'x' || w+net >= dist[i][v]) continue;
                dist[i][v] = w+net;
                pq.push(mpr(dist[i][v], v));
            }
        }
    }
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0 ; i<m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].pb(mpr(b-1, c));
        adj[b-1].pb(mpr(a-1, c));
    }

    string s;
    cin >> s;

    vector<vector<int>> dist(n, vector<int>(n));
    dijkstra_all_pair(s, adj, dist, n);
    while(q--)
    {
        int choice;
        cin >> choice;

        if(choice)
        {
            int num;
            cin >> num;
            if(s[num-1] == '.') s[num-1] = 'x';
            else s[num-1] = '.';
            dijkstra_all_pair(s, adj, dist, n);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << (dist[a-1][b-1] >= INT_MAX*1000LL ? -1 : dist[a-1][b-1]) << "\n";
        }

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

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}