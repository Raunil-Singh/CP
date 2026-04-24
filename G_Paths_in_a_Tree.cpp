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

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x; cin >> x; return x;
}

void result(int ans) {
    cout << "! " << ans << endl;
    return;
}

void solve(int tc_no) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for(int i = 1 ; i<n ; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<int> single;
    for(int i = 0 ; i<n ; i++) single.insert(i);

    vector<pair<int, int>> pairs;

    vector<int> par(n);

    function<void(int, int)> dfs = [&](int prev, int curr) {
        par[curr] = prev;
        if(single.find(prev) != single.end()) {
            pairs.push_back(mpr(curr, prev));
            single.erase(prev);
            single.erase(curr);
        }

        for(int next : adj[curr]) {
            if(next == prev) continue;
            dfs(curr, next);
        }
    };

    dfs(-1, 0);

    while(single.size() > 1) {
        int a = *single.begin(); single.erase(a);
        int b = *single.begin(); single.erase(b);
        pairs.push_back(mpr(a, b));
    }

    for(auto [a, b] : pairs) {
        if(query(a+1, b+1)) {
            if(query(a+1, a+1)) result(a+1);
            else result(b+1);
            return;
        }
    }

    if(single.size() == 1) {
        result((*single.begin())+1);
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