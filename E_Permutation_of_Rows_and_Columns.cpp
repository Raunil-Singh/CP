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
#define MOD

void preprocessing()
{

    // Code here

}

void next(vector<vector<int>> &mat, vector<int> &h, vector<int> &v) {
    int n = mat.size(), m = mat[0].size();
    for(int i = 0 ; i<n ; i++) {
        set<int> s(mat[i].begin(), mat[i].end());
        for(int j = 0 ; j<m ; j++) {
            if(s.lower_bound(mat[i][j]+1) == s.end()) continue;
            h[mat[i][j]] = *s.lower_bound(mat[i][j]+1);
        }
    }
    for(int i = 0 ; i<m ; i++) {
        set<int> s;
        for(int j = 0 ; j<n ; j++) s.insert(mat[j][i]);
        for(int j = 0 ; j<n ; j++) {
            if(s.lower_bound(mat[j][i]+1) == s.end()) continue;
            v[mat[j][i]] = *s.lower_bound(mat[j][i]+1);
        }
    }
}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> m1(n, vector<int>(m));
    for(vector<int> &x : m1) inp(x);
    vector<vector<int>> m2(n, vector<int>(m));
    for(vector<int> &x : m2) inp(x);

    vector<int> h1(m*n+1, -1), h2(m*n+1, -1), v1(m*n+1, -1), v2(m*n+1, -1);

    next(m1, h1, v1);
    next(m2, h2, v2);

    bool flag = true;
    for(int i = 0 ; i<=m*n ; i++) {
        if(h1[i] != h2[i] || v1[i] != v2[i]) flag = false;
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";
    
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