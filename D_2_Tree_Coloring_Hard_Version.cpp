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

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i<n ; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> cnt(n);
    vector<int> par(n+1);
    vector<int> id(n+1);
    int ans = 0;
    function<void(int, int, int lvl)> dfs = [&](int prev, int curr, int lvl) {
        id[curr] = cnt[lvl];
        cnt[lvl]++;
        par[curr] = prev;
        int child_count = 0;
        for(int next : adj[curr]) {
            if(next == prev) continue;
            dfs(curr, next, lvl+1);
            child_count++;
        }
        ans = max(ans, child_count + 1);
    };

    dfs(0, 1, 0);
    ans = max(ans, *max_element(all(cnt)));

    cout << ans << "\n";

    vector<int> clist(ans);
    for(int i = 0 ; i<ans ; i++) clist[i] = i;

    vector<int> color(n+1);

    #define PQ priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    PQ *q1 = new PQ(), *q2 = new PQ();
    
    q1->push({id[1], 1});

    while(!q1->empty()) {
        int zero = q1->top().second;
        while(!q1->empty()) {
            auto [i, curr] = q1->top();
            q1->pop();
            if(color[par[curr]] == clist[i]) {
                if(i+1 == ans) {
                    swap(clist[0], clist[i]);
                    color[zero] = clist[0];
                } else {
                    swap(clist[i], clist[ans-1]);
                }
            }
            color[curr] = clist[i];
            for(int next : adj[curr]) {
                if(next == par[curr]) continue;
                q2->push({id[next], next});
            }
        }
        swap(q1, q2);
    }

    vector<vector<int>> mappings(ans);
    for(int i = 1 ; i<=n ; i++) {
        mappings[color[i]].push_back(i);
    }

    for(auto x : mappings) {
        cout << x.size() << " ";
        for(int num : x) cout << num << " ";
        cout << "\n";
    }

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
    cin >> t; // Update me!
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