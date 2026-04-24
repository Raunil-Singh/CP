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

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

void res(int x) {
    cout << "! " << x << endl;
}

void solve(int tc_no)
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> vp(q);
    for(int i = 0 ; i<q ; i++) {
        int a, b;
        cin >> a >> b;
        vp[i] = mpr(a, b);
    }

    sort(all(vp), [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        if(a.first < b.first || (a.first == b.first && a.second > b.second)) return true;
        else return false;
    });

    set<pair<int, int>> st;
    pair<int , int> prev = {0, 0};
    for(int i = 0 ; i<q ; i++) {
        if((prev.first <= vp[i].first && prev.second >= vp[i].second)) continue;
        else {
            prev = vp[i];
            st.insert(vp[i]);
        }
    }

    int half = query(1, n/2);

    int ans = (half > 0);
    for(pair<int, int> p : st) {
        if(half && p.first <= n/2) ans = max(ans, query(p.first, p.second));
        else if(!half && p.second > n/2) ans = max(ans, query(p.first, p.second));
    }

    res(ans);

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