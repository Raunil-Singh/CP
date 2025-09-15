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
#define MOD 998244353

void preprocessing()
{

    // Code here

}

class dsu {
    vector<int> par;
    vector<int> rnk;
public:
    dsu(int k) : par(k), rnk(k, 1) {
        for(int i = 0 ; i<k ; i++) par[i] = i;
    }

    int get_par(int node) {
        if(node == par[node]) return node;
        else return par[node] = get_par(par[node]);
    }
    void unio(int a, int b) {
        int pa = get_par(a), pb = get_par(b);
        if(rnk[pa] >= rnk[pb]) {
            rnk[pa] += rnk[pb];
            par[pb] = pa;
        } else {
            rnk[pb] += rnk[pa];
            par[pa] = pb;
        }
    }
    int get_component_size(int a) {
        return rnk[get_par(a)];
    }
};

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int power(int a, int b) {
    if(b == 0) return 1;
    if(a == 0) return a;
    if(b % 2) return mul(a, power(mul(a, a), b/2));
    else return power(mul(a, a), b/2);
}

void solve(int tc_no)
{
    int n, s;
    cin >> n >> s;
    dsu d(n);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 1 ; i<n ; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        pq.push({w, a-1, b-1});
    }
    int ans = 1;
    while(!pq.empty()) {
        vector<int> curr = pq.top();
        pq.pop();
        int a = curr[1], b = curr[2], w = curr[0];
        ans = mul(ans, power(add(s-w, 1), d.get_component_size(a) * d.get_component_size(b) - 1));
        d.unio(a, b);
    }
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