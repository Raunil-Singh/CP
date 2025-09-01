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
#define MOD 1000000007LL

int power(int a, int b) {
    int result = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

int inv(int a) {
    return power(a, MOD - 2);
}

int mul(int a, int b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

int add(int a, int b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}

void dfs(int curr, vector<vector<int>> &adj, vector<int> &l, vector<int> &h) {
    if(adj[curr].size() == 0) {
        h[curr] = 1;
        l[curr] = 0;
        return;
    }
    for(int next : adj[curr]) {
        dfs(next, adj, l, h);
    }
    int cnt = adj[curr].size();
    vector<int> pref(cnt, 1);
    vector<int> suff(cnt, 1);
    for(int i = 1 ; i<cnt ; i++) {
        pref[i] = mul(pref[i-1], add(l[adj[curr][i-1]], h[adj[curr][i-1]]));
    }
    for(int i = cnt-2 ; i>=0 ; i--) {
        suff[i] = mul(suff[i+1], add(l[adj[curr][i+1]], h[adj[curr][i+1]]));
    }
    l[curr] = mul(suff[0], add(l[adj[curr][0]], h[adj[curr][0]]));
    for(int i = 0 ; i<cnt ; i++) {
        h[curr] = add(h[curr], mul(mul(pref[i], suff[i]), h[adj[curr][i]]));
    }
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

    int n;
    cin >> n;
    
    vector<vector<int>> adj(n+1);
    for(int i = 2 ; i<=n ; i++) {
        int num;
        cin >> num;
        adj[num].push_back(i);
    }

    vector<int> l(n+1, 0), h(n+1, 0);
    dfs(1, adj, l, h);

    cout << add(l[1], h[1]) << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}