#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

#define int int64_t // upto 9.2 * (10^18)
#define uint uint64_t // upto 1.8 * (10^19)
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ":\n";

    int n, rem;
    cin >> n >> rem;

    vector<int> p(n,-1);
    vector<vector<int>> adj(n);
    for(int i = 1 ; i<n ; i++) {
        int x; cin >> x; x--;
        p[i] = x;
        adj[x].push_back(i);
    }

    vector<int> sec(n, -1);
    vector<int> depth(n);

    function<int(int, int)> dfs = [&](int curr, int d)->int {
        depth[curr] = d;
        d++;
        int secondary = (adj[curr].size() == 0 ? curr : -1);
        for(int next : adj[curr]) secondary = max(dfs(next, d), secondary);
        d--;
        return sec[curr] = secondary;
    };
    dfs(0,0);

    vector<int> dist(n);
    dist[0] = 1;
    dist[n-1] = depth[n-1];
    for(int i = 1 ; i<n-1 ; i++) {
        if(p[(i+1)%n] == i) dist[i] = 1;
        else dist[i] = 2 + depth[i] - depth[(i+1)%n];
    }

    int left = n, ans = 0;
    for(int i = 1 ; i<n ; i++) {
        int node, w; cin >> node >> w;
        rem -= w;
        node--;
        dist[node-1]--;
        ans += w;
        if(dist[node-1] == 0) left--;
        if(sec[node] != -1) {
            dist[sec[node]]--;
            ans += w;
            if(dist[sec[node]] == 0) left--;
        }

        cout << ans + rem*left << " ";
    }

    cout << "\n";

}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    compute the number of the edges in the path between 2 nodes using rev dfs trick
    algo in notebook
    
****/

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


// ======= CHECKLIST =======
// Notebook  : y
// Using it? : y
// Sol Proof : y
// algo noted: 
// Update the number of testcases: 
// Start coding ;)