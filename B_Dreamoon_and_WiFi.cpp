#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>
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
    string send, recv;
    cin >> send >> recv;

    int tar = 0, curr = 0, n = send.size(), unk = 0;
    for(int i = 0 ; i<n ; i++) {
        if(send[i] == '+') tar++;
        else tar--;
        if(recv[i] == '?') unk++;
        else if(recv[i] == '+') curr++;
        else curr--;
    }

    if(unk == 0 || abs(tar-curr) > unk) {
        if(tar == curr) cout << "1\n";
        else cout << 0 << "\n";
        return;
    }

    vector<vector<int>> cnt(unk+1, vector<int>(2*unk+5));
    cnt[0][unk+1] = 1;
    for(int i = 1 ; i<=unk ; i++) {
        for(int j = 1 ; j<=2*unk+1 ; j++) cnt[i][j] = cnt[i-1][j-1] + cnt[i-1][j+1];
    }

    int sum = accumulate(all(cnt[unk]), (int)0);
    double p = cnt[unk][unk+1 + tar - curr]/(((double)1.0) * sum);
    cout << p << "\n";

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

    cout << fixed;
    cout << setprecision(15);

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