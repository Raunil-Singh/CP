#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>
#include <unistd.h>
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
    int n;
    cin >> n;
    vector<int> even, odd;
    for(int i = 0 ; i<n ; i++) {
        int x; cin >> x;
        if(x%2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    int cnt_even = even.size();

    if(odd.size() == 0) {
        for(int i = 0 ; i<n ; i++) cout << "0 ";
        cout << "\n";
        return;
    }

    sort(all(even), greater<int>());
    sort(all(odd), greater<int>());

    int sum = accumulate(all(even), (int)0);
    int min = (cnt_even > 0 ? *min_element(all(even)) : 0);
    for(int i = 1 ; i<cnt_even ; i++) even[i] += even[i-1];

    for(int i = 1 ; i<=n ; i++) {
        int cnt_odd = odd.size() - 1;
        int ans = 0;
        if(i <= cnt_even + 1) {
            ans = odd[0];
            if(i>1) ans += even[i-2];
        } else if((i - (cnt_even+1)) % 2 == 1) {
            if((cnt_even > 0 && cnt_odd - (i - (cnt_even+1)) > 0)) ans = odd[0] + sum - min;
            else ans = 0;
        }
        else ans = odd[0] + sum;
        cout << ans << " ";
    }

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
    cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}