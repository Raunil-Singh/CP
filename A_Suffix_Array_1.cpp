#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <utility>
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
    string s;
    cin >> s;

    s.push_back('$');

    int n = s.length();

    vector<int> ans(n);

    map<char, int> mpp2;
    for(int i = 0 ; i<n ; i++) {
        mpp2[s[i]] = 0;
    }
    int rnk = 0;
    for(auto &x : mpp2) {
        x.second = rnk;
        rnk++;
    }
    for(int i = 0 ; i<n ; i++) ans[i] = mpp2[s[i]];
    
    vector<vector<int>> v(n, vector<int>(2));
    vector<vector<int>> res(n, vector<int>(2));
    for(int step = 1 ; step <= 2*n ; step <<= 1) {
        for(int i = 0 ; i<n ; i++) {
            mpp[make_pair(ans[i], ans[(i + step) % n])].push_back(i);
        }
        rnk = 0;
        for(auto &b : mpp) {
            for(auto x : b.second) {
                ans[x] = rnk;
            }
            rnk++;
        }
        mpp.clear();
    }
    
    vector<int> final(n);
    for(int i = 0 ; i<n ; i++) final[ans[i]] = i;

    for(int x : final) cout << x << " ";
    cout << "\n";

}

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
    // cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}