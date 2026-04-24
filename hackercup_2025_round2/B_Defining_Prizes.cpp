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

void solve(int tc_no)
{
    
    cout << "Case #" << tc_no << ": ";
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> mpp;
    for(int i = 0 ; i<n ; i++) {
        int x;
        cin >> x;
        mpp[x]++;
    }

    vector<int> b(m); inp(b);
    sort(all(b), greater<int>());

    // while(b.size() > 0 && b.back() == 0) b.pop_back();

    vector<pair<int, int>> aox;
    for(auto [x, y] : mpp) {
        aox.push_back(mpr(x, y));
    }

    sort(all(aox), greater<pair<int, int>>());

    vector<int> a(aox.size());
    
    a[0] = aox[0].second;
    
    for(int i = 1 ; i<a.size() ; i++) {
        a[i] = a[i-1] + aox[i].second;
    }

    function<bool(int)> check = [&](int cnt) -> bool {
        int curr = -1, left = 0;
        for(int pos = cnt ; pos >= 0 ; pos--) {
            int pres = a[pos];
            pres -= left;
            left = 0;
            while(pres > 0) {
                curr++;
                if(curr == b.size()) return false;
                left = min(b[curr], a[pos]);
                int use = min(pres, left);
                pres -= use;
                left -= use;
            }
        }
        return true;
    };

    int l = -1, r = a.size();

    while(l+1 < r) {
        int mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    if(l == -1) cout << "0\n";
    else cout << a[l] << '\n';
    
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("defining_prizes_validation_input.txt", "r", stdin);
    freopen("defining_prizes_validation_output.txt", "w", stdout);

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