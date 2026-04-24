#include <algorithm>
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
#define MOD 998244353LL

void preprocessing()
{

    // Code here

}

int pc(int x, int y) {
    if(y == 0) return 1;
    else if(y == 1) return x % MOD;
    else if(y%2) return (x * pc((x*x) % MOD, y/2)) % MOD;
    else return pc((x*x) % MOD, y/2) % MOD;
}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i = 1 ; i<=n ; i++) cin >> v[i];
    vector<int> sign(n+1);

    for(int i = 1 ; i<=n ; i++) {
        if(v[i] < 0) sign[i] = 1;
        v[i] = abs(v[i]);
    }

    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> par(n+1);
    vector<int> subtree_sum(n+1);
    vector<int> subtree_sign(n+1);

    function<void(int, int)> dfs_prec = [&](int prev, int curr) {

        par[curr] = prev;
        subtree_sum[curr] = v[curr];
        subtree_sign[curr] = sign[curr];

        for(auto next : adj[curr]) {
            if(next == prev) continue;
            dfs_prec(curr, next);
            subtree_sum[curr] += subtree_sum[next];
            subtree_sign[curr] += subtree_sign[next];
        }

    };

    int s = 1;

    dfs_prec(0, 1);

    int tot = accumulate(all(v), 0LL);
    int negcnt = accumulate(all(sign), 0LL);

    int cnt = 0;

    if(negcnt % 2 == 0) cnt = tot;

    for(int i = 1 ; i <= n ; i++) {
        
        // remove subtree first and see
        if((negcnt - subtree_sign[i]) % 2 == 0) {
            cnt = max(cnt, tot - subtree_sum[i]);
        }

        // now compute for all children
        for(int next : adj[i]) {
            if(next == par[i]) continue;
            if(subtree_sign[next] % 2 == 0) {
                cnt = max(cnt, subtree_sum[next]);
            }
        }

    }

    // happens when all neg
    if(cnt == 0) {
        s = -1;
        cnt = *min_element(all(v));
    }

    // cout << cnt << " " << s << "\n";

    int ans = pc(2, cnt);
    
    ans = (ans * s + 10*MOD) % MOD;

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