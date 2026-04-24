#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#define FAST_IO ;
#else
#define dbg(x, ...) ;
#endif

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
#define MOD ((int64_t) 998244353)

inline void preprocessing() {

    // Code here

}

class LCA {
public:
    int n, LOG;
    vector<vector<int>> up;
    vector<int> lvl;
    
    LCA(const vector<vector<int>>& adj, int root = 0) {
        n = adj.size();
        LOG = 64 - __builtin_clz(n);
        up.assign(n, vector<int>(LOG, -1));
        lvl.resize(n);
        dfs(adj, -1, root, 0);
        preprocess();
    }
    
    int getLCA(int a, int b) {
        if (lvl[a] < lvl[b]) swap(a, b);
        int diff = lvl[a] - lvl[b];
        for (int i = 0; i < LOG; i++)
            if (diff & (1LL << i)) a = up[a][i];
        if (a == b) return a;
        
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    }

    int get_dist(int a, int b) {
        int p = getLCA(a, b);
        return lvl[a] + lvl[b] - lvl[p]*2;
    }

    int get_lvl(int a) {
        return lvl[a];
    }

    int get_par(int a) {
        return up[a][0];
    }

    
private:
    void dfs(const vector<vector<int>>& adj, int prev, int curr, int depth) {
        up[curr][0] = prev;
        lvl[curr] = depth;
        for (int next : adj[curr]) {
            if (next != prev) dfs(adj, curr, next, depth + 1);
        }
    }
    
    void preprocess() {
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j < n; j++) {
                if (up[j][i - 1] != -1)
                    up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
};


void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 1 ; i<n ; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LCA lc(adj);

    pair<int, int> lp = {0, 1};
    int max_dist = lc.get_dist(lp.first, lp.second);

    function<int(int, int)> dfs = [&](int prev, int curr) -> int {
        int b1 = curr, b2 = curr;
        for(int next : adj[curr]) {
            if(next == prev) continue;
            int present = dfs(curr, next);
            if(lc.get_lvl(b1) < lc.get_lvl(present)) swap(b1, present);
            if(lc.get_lvl(b2) < lc.get_lvl(present)) swap(b2, present);
        }

        int dist = lc.get_dist(b1, b2);
        if(dist > max_dist) {
            max_dist = dist;
            lp = {b1, b2};
        }

        return b1;
    };

    dfs(-1, 0);

    queue<int> q;
    int lca = lc.getLCA(lp.first, lp.second);

    vector<int> dist(n, INT_MAX);
    dist[lca] = 0;

    q.push(lca);

    int curr = lp.first;
    while(curr != lca) {
        q.push(curr);
        dist[curr] = 0;
        curr = lc.get_par(curr);
    }
    curr = lp.second;
    while(curr != lca) {
        q.push(curr);
        dist[curr] = 0;
        curr = lc.get_par(curr);
    }

    for(int i = 1 ; !q.empty() ; i++) {
        int x = q.size();
        while(x--) {
            int curr = q.front(); q.pop();
            for(int next : adj[curr]) {
                if(dist[next] <= i) continue;
                dist[next] = i;
                q.push(next);
            }
        }
    }

    auto x = max_element(all(dist));
    int idx = x - dist.begin();
    while(idx == lp.first || idx == lp.second) {
        idx = (idx + 1) % n;
    }
    cout << max_dist + (*max_element(all(dist))) << "\n";
    
    cout << lp.first+1 << " " << lp.second+1 << " " << idx+1 << "\n";


}
// Note: Ensure all template parameters are updated!

/****              Algorithm keypoints:
    here:
    
    
    
****/

int32_t main() {
    #ifdef BG
    auto begin = std::chrono::high_resolution_clock::now();
    #else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    // cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    #ifdef BG
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif

    return 0;
}


// ======= CHECKLIST =======
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)