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

#define int long long // upto 9.2 * (10^18)
#define uint unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD 1000000007

vector<int> fact;

void preprocessing()
{
    int cnt = 1000000;
    fact.assign(cnt+1, 1);
    for(int i = 2 ; i<=cnt ; i++) fact[i] = (fact[i-1] * i) % MOD;
}

bool is_tree(int prev, int curr, vector<vector<int>> &adj, vector<bool> &seen) {
    if(seen[curr]) return false;
    seen[curr] = true;
    for(int next : adj[curr])
        if(prev == next) continue;
        else if(!is_tree(curr, next, adj, seen)) return false;
    return true;
}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for(int i = 0 ; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }

    vector<bool> seen(n, false);
    if(!is_tree(-1, 0, adj, seen)) {
        cout << "0\n";
        return;
    }

    vector<bool> leaves(n);
    for(int i = 0 ; i<n ; i++) if(deg[i] == 1) leaves[i] = true;


    vector<int> count(n);
    for(int leaf = 0 ; leaf<n ; leaf++) {
        if(!leaves[leaf]) continue;
        // count[leaf] = 1;
        for(int neighbor : adj[leaf]) count[neighbor]++;
    }

    int ans = 2;
    int cnt = 0;
    for(int i = 0 ; i<n ; i++) {
        if(deg[i] - count[i] > 2) {
            cout << "0\n";
            return;
        } else if(deg[i] - count[i] != 0 && !leaves[i]) cnt++;
        ans = (ans*fact[count[i]]) % MOD;
    }
    if(cnt > 0) ans = (ans * 2) % MOD;
    cout << ans << "\n";
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t;
    cin >> t;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}