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
    
    // cout << "Case #" << tc_no << ":\n";
    int n;
    cin >> n;
    vector<string> vs(n); inp(vs);
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> cnt(n, 0);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            v[i][j] = vs[i][j] - '0';
            cnt[i] += v[i][j];
        }
        if(v[i][i] == 0) {
            cout << "NO\n";
            return;
        }
        cnt[i]--;
        v[i][i] = 0;
    }

    vector<pair<int, int>> vp;
    queue<int> q; // nodes that don't have anything going out of them

    for(int i = 0 ; i<n ; i++) {
        if(cnt[i] == 0) q.push(i);
    }

    // cout << "Queue Size : " << q.size() << "\n";

    vector<int> chosen(n, 0);
    queue<int> next_q;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int i = 0 ; i<n ; i++) {
            chosen[i] = 0;

            if(v[i][curr] == 0) continue;
            next_q.push(i);
            chosen[i] = 1;
            cnt[i]--;
            if(cnt[i] == 0) q.push(i);
        }
        // cout << curr << " : ";
        // for(int x : chosen) cout << x << " ";
        // cout << "\n";
        while(!next_q.empty()) {
            auto next = next_q.front(); next_q.pop();
            for(int i = 0 ; i<n ; i++) {
                if(chosen[i]==1 && (v[next][i]==1)) goto NEXT;
            }
            vp.push_back({next, curr});
            NEXT:;
        }
    }

    if(vp.size() != n-1) {
        cout << "NO" << "\n";
        return;
    }

    {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i<vp.size() ; i++) {
            adj[vp[i].first].push_back(vp[i].second);
            adj[vp[i].second].push_back(vp[i].first);
        }

        vector<vector<int>> dup(n, vector<int>(n));
        
        bool flag = true;
        function<void(int, int, int, vector<bool>&)> dfs = [&](int t, int prev, int curr, vector<bool>& visited) {
            dup[t][curr] = 1;
            visited[curr] = true;
            for(auto next : adj[curr]) {
                if(prev == next) continue;
                if(visited[next]) {
                    flag = false;
                    continue;
                }
                dfs(t, curr, next, visited);
            }
        };

        for(int x = 0 ; x<n ; x++) {
            vector<bool> visited(n, false);
            dfs(x, -1, x, visited);
        }

        if(!flag) {
            cout << "NO\n";
            return;
        }
    }

    vector<vector<int>> adj(n);
    for(int i = 0 ; i<vp.size() ; i++) {
        adj[vp[i].first].push_back(vp[i].second);
    }

    vector<vector<int>> dup(n, vector<int>(n));
    
    bool flag = true;
    function<void(int, int, int, vector<bool>&)> dfs = [&](int t, int prev, int curr, vector<bool>& visited) {
        dup[t][curr] = 1;
        visited[curr] = true;
        for(auto next : adj[curr]) {
            if(prev == next) continue;
            if(visited[next]) {
                flag = false;
                continue;
            }
            dfs(t, curr, next, visited);
        }
    };

    for(int x = 0 ; x<n ; x++) {
        vector<bool> visited(n, false);
        dfs(x, -1, x, visited);
    }

    for(int i = 0 ; i<n ; i++) {
        for(int j = 0 ; j<n ; j++) {
            if(i == j) continue;
            if(dup[i][j] != v[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for(auto [a, b] : vp) cout << a+1 << " " << b+1 << "\n";

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