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
    
    // cout << "Case #" << tc_no << ": ";
    int n, m;
    cin >> n >> m;

    vector<set<int>> adjr(n); 
    vector<set<int>> adjb(n);

    for(int i = 0 ; i<m ; i++) {
        int a, b; string c;
        cin >> a >> b >> c;
        a--; b--;
        if(c == "B") {
            adjb[a].insert(b);
            adjb[b].insert(a);
            // cout << "# ";
        } else {
            adjr[a].insert(b);
            adjr[b].insert(a);
            // cout << "@ ";
        }
    }
    // cout << "\n";

    map<pair<int,int>, int> d0;
    queue<pair<int, int>> q;
    q.push({0, 0});

    for(int dist = 0 ; dist <= n ; dist++) {
        int x = q.size();
        while(x--) {
            auto p = q.front(); q.pop();
            if(d0.find(p) != d0.end()) continue;
            d0[p] = dist;
            // red
            int bal = p.second + 1;
            for(auto next : adjr[p.first]) {
                if(d0.find({next, bal}) == d0.end()) {
                    q.push({next, bal});
                }
            }
            bal = p.second - 1;
            for(auto next : adjb[p.first]) {
                if(d0.find({next, bal}) == d0.end()) {
                    q.push({next, bal});
                }
            }
        }
        // cout << q.size() << " ";
    }
    // cout << "\n";

    map<pair<int,int>, int> dn;
    while(!q.empty()) q.pop();
    q.push({n-1, 0});

    for(int dist = 0 ; dist <= n ; dist++) {
        int x = q.size();
        while(x--) {
            auto p = q.front(); q.pop();
            if(dn.find(p) != dn.end()) continue;
            dn[p] = dist;
            // red
            int bal = p.second + 1;
            for(auto next : adjr[p.first]) {
                if(dn.find({next, bal}) == dn.end()) {
                    q.push({next, bal});
                }
            }
            bal = p.second - 1;
            for(auto next : adjb[p.first]) {
                if(dn.find({next, bal}) == dn.end()) {
                    q.push({next, bal});
                }
            }
        }
        // cout << q.size() << " ";
    }
    // cout << "\n";

    int ans = (d0.find({n-1, 0})!=d0.end() ? d0[{n-1, 0}] : INT_MAX);
    // cout << "Init ans : " << ans << "\n";

    set<int> safe;
    for(int i = 0 ; i<n ; i++) {
        if(adjr[i].size() && adjb[i].size()) {
            safe.insert(i);
        }
    }

    map<int, vector<pair<int, int>>> queues;
    for(auto [a, b] : dn) {
        if(safe.find(a.first) == safe.end()) continue;
        queues[a.first].push_back(make_pair(a.second, b));
    }

    for(auto [a, b] : d0) {
        int node = a.first;
        if(safe.find(node) == safe.end()) continue;
        for(auto [c, d] : queues[node]) {
            if(abs(a.second + c) % 2 != 0) continue;
            ans = min(ans, b + d + abs(a.second + c));
            // cout << node << " " << b << " " << d << " " << a.second << " " << c.second << "\n";
            // cout << ans << "\n";
        }
    }

    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans << "\n";
    
}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    
    
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
    // cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


// ======= CHECKLIST =======
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)