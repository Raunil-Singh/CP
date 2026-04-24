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

int compute_answer(vector<set<int>> &adj, int pd, int dis, vector<int> &par, int n, string s) {

    function<void(int, int)> relabel = [&](int prev, int curr) {
        par[curr] = prev;
        for(int next : adj[curr]) {
            if(next == prev) continue;
            relabel(curr, next);
        }
    };

    relabel(n-1, n-1);

    // for(int i = 0 ; i<n ; i++) cout << i+1 << ":" << par[i]+1 << " ";
    // cout << "\n";

    int ans = 0;
    queue<int> q;

    s[0] = '1';
    s[n-1] = '1';

    for(int i = 1 ; i < n-1 ; i++) {
        if(s[i] == '1') q.push(i);
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans++;
        x = par[x];
        if(s[x] == '0') {
            q.push(x);
            s[x] = '1';
        }
    }

    return ans;

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;

    vector<int> par(n);
    vector<set<int>> adj(n);
    for(int i = 1 ; i<n ; i++) {
        int x; cin >> x; x--;
        adj[i].insert(x);
        adj[x].insert(i);
        par[i] = x;
    }

    string s;
    cin >> s;
    
    vector<int> lvl(n);
    function<void(int, int)> fill_lvl = [&](int curr, int l) {
        lvl[curr] = l;
        l++;
        for(int next : adj[curr]) {
            if(par[curr] == next) continue;
            fill_lvl(next, l);
        }
    };
    fill_lvl(0, 0);

    // for(int i = 0 ; i<n ; i++) cout << i+1 << ":" << lvl[i] << " ";
    // cout << "\n";

    // for(int i = 0 ; i<n ; i++) cout << i+1 << ":" << par[i]+1 << " ";
    // cout << "\n";

    int ans = INT_MAX;
    
    int dis = n-1;
    while(dis != 0) {
        int pd = par[dis];
        adj[pd].erase(dis);
        adj[dis].erase(pd);
        ans = min(ans, compute_answer(adj, pd, dis, par, n, s));
        adj[pd].insert(dis);
        adj[dis].insert(pd);
        dis = pd;
    }

    cout << ans * 2 << "\n";

    
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