#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <queue>
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

    vector<vector<int>> v(n);
    for(int i = 0 ; i<n ; i++) {
        int x;
        cin >> x;
        set<int> seen;
        vector<int> temp(x); inp(temp); reverse(all(temp));
        for(int num : temp) {
            if(seen.find(num) != seen.end()) continue;
            v[i].push_back(num);
            seen.insert(num);
        }
    }

    set<int> seen;
    vector<vector<int>> res;

    #define PQ priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>

    PQ *s1 = new PQ(all(v)), *s2 = new PQ();
    while(!s1->empty()) {
        res.push_back(s1->top());
        seen.insert(all(res.back()));
        while(!s1->empty()) {
            vector<int> temp;
            for(int x : s1->top()) {
                if(seen.find(x) == seen.end()) temp.push_back(x);
            }
            s1->pop();
            if(temp.size() > 0)
            s2->push(temp);
        }
        swap(s1, s2);
    }

    for(auto x : res) for(auto xv : x) cout << xv << " ";
    cout << "\n";

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