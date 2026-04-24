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
    int n{}, m{};
    cin >> n >> m;

    vector<vector<int>> vs(n, vector<int>(m));
    for(auto &x: vs) inp(x);

    vector<queue<int>> don(m);
    vector<queue<int>> recv(m);

    int cnt{};
    for(int i{} ; i<n ; i++) {
        for(int j{} ; j<m ; j++) {
            if(vs[i][j]) cnt++;
        }
    }

    if(cnt % n != 0) {
        cout << "-1\n";
        return;
    }

    cnt /= n;

    vector<int> curr(n);

    vector<bool> done(n);

    for(int i {} ; i<n ; i++) {
        for(int j {} ; j<m ; j++) {
            if(vs[i][j] == 1) {
                curr[i] ++;
            }
        }
        if(curr[i] > cnt) {
            for(int j {} ; j<m ; j++) {
                if(vs[i][j] == 1)
                    don[j].push(i);
            }
        }
        else if(curr[i] < cnt) {
            for(int j {} ; j<m ; j++) {
                if(vs[i][j] == 0)
                    recv[j].push(i);
            }
        } else {
            done[i] = true;
        }
    }

    vector<vector<int>> ans;

    for(int i {} ; i<m ; i++) {
        while (recv[i].size() && don[i].size()) {
            if(done[don[i].front()]) {
                don[i].pop();
                continue;
            } else if(done[recv[i].front()]) {
                recv[i].pop();
                continue;
            }
            int x {don[i].front()}, y{recv[i].front()};
            don[i].pop();
            recv[i].pop();
            curr[x]--;
            curr[y]++;
            if(curr[x] == cnt) done[x] = true;
            if(curr[y] == cnt) done[y] = true;
            ans.push_back({x, y, i});
        }
    }
    
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x[0]+1 << " " << x[1]+1 << " " << x[2]+1 << "\n";
    
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

    int t{};
    cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}