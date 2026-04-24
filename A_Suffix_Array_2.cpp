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

void stableCountingSort(vector<pair<int, int>>& arr, int digit_index, int max_val) {
    int n = arr.size();
    if (n == 0) return;

    int k = max_val + 1;
    vector<int> count(k, 0);
    vector<pair<int, int>> output(n);

    for (int i = 0; i < n; i++) {
        int key = (digit_index == 1) ? arr[i].first : arr[i].second;
        count[key]++;
    }

    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int key = (digit_index == 1) ? arr[i].first : arr[i].second;
        output[count[key] - 1] = arr[i];
        count[key]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void sortPairs(vector<pair<int, int>>& pairs, int max_key_val) {

    stableCountingSort(pairs, 2, max_key_val);
    stableCountingSort(pairs, 1, max_key_val);
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
    
    unordered_map<int, int> mpp;
    vector<int> temp(n);
    vector<int> count(n+1, 0);
    vector<int> output(2*n);
    vector<int> vpp(2*n);

    for(int step = 1 ; step <= 2*n ; step <<= 1) {
        for(int i = 0 ; i<n ; i++) {
            temp[i] = ans[i];
            mpp[ans[i]*n + ans[(i+step)%n]] = 0;
        }

        int k = mpp.size();


        
        for(int i = 0 ; i<vpp.size() ; i+=2) mpp[vpp[i]*n + vpp[i+1].second] = i;
        for(int i = 0 ; i<n ; i++) {
            ans[i] = mpp[temp[i]*n + temp[(i+step)%n]];
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