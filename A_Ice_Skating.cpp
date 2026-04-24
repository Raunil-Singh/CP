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
    int n; cin >> n;

    vector<int> par(n);
    vector<int> rnk(n);
    for(int i = 0 ; i<n ; i++) {
        par[i] = i;
        rnk[i] = 1;
    }
    
    vector<vector<int>> x(1001), y(1001);
    for(int i = 0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(i);
        y[b].push_back(i);
    }

    function<int(int)> find = [&](int x) -> int {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    };

    function<void(int, int)> unio = [&](int a, int b) {
        int pa = find(a), pb = find(b);
        if(rnk[pa] >= rnk[pb]) {
            par[pb] = pa;
            rnk[pa] += rnk[pb];
        } else {
            par[pa] = pb;
            rnk[pb] += rnk[pa];
        }
    };

    for(int i = 0 ; i<=1000 ; i++) {
        for(int j = 1 ; j<x[i].size() ; j++) unio(x[i][j-1], x[i][j]);
        for(int j = 1 ; j<y[i].size() ; j++) unio(y[i][j-1], y[i][j]);
    }

    set<int> roots; for(int i = 0 ; i<n ; i++) roots.insert(find(i));

    cout << roots.size()-1 << "\n";


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