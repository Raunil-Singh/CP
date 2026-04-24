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
    int n, k;
    cin >> n >> k;
    vector<int> v(n); inp(v);

    vector<int> state(n+1);
    for(int num : v) {
        if(num < n) state[num] = 1;
    }

    int cnt = k;
    for(int i = 0 ; i<n ; i++) {
        if(cnt > 0 && state[i] == 0) {
            state[i] = 2;
            cnt--;
        }
    }

    int mex = 0;
    for(int i = 0 ; i<=n ; i++) {
        if(state[i] == 0) {
            mex = i;
            break;
        }
    }

    map<int, int> mpp;
    for(int num : v) {
        if(num > mex)
        mpp[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto [a, b] : mpp) {
        pq.push({b, a});
    }

    for(int moves = k ; moves > 0 && !pq.empty() ; ) {
        auto [cnt, curr] = pq.top();
        pq.pop();
        int del = min(moves, cnt);
        mpp[curr] -= del;
        if(mpp[curr] == 0) {
            mpp.erase(curr);
        }
        else if(cnt - del > 0) pq.push({cnt - del, curr});
        moves -= del;
    }

    int unique = mex + mpp.size();

    cout << unique - mex << "\n";

}
// Note: Ensure all template parameters are updated!

/****              Algorithm keypoints:
    here:
    
    num < n. We don't touch these.
    
    if num >= n. We first try to find the single numbers and 
    
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