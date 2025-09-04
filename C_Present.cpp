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

bool check (int h, vector<int> &v, int m, int w) {
    int n = v.size();
    vector<int> del(n+1);
    int ops = 0;
    for(int i = 0 ; i<n ; i++) {
        if(i > 0) del[i] += del[i-1];
        if(v[i] + del[i] < h) {
            int diff = h - v[i] - del[i];
            ops += diff;
            del[min(n, i + w)] -= diff;
            del[i] += diff;
        }
    }
    return ops <= m;
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

    int n, m, w;
    cin >> n >> m >> w;

    vector<int> v(n); inp(v);

    int l = 0, r = INT_MAX;
    while(l + 1 < r) {
        int mid = (l + r)/2;
        if(check(mid, v, m, w)) l = mid;
        else r = mid;
    }

    cout << l << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}