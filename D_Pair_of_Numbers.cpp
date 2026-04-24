#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#else
#define dbg(x, ...) ;
#endif

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
    int n;
    cin >> n;
    vector<int> v(n); inp(v);

    int g = v[0];
    for(int num : v) g = gcd(g, num);

    if(g == *min_element(all(v))) {
        cout << 1 << " " << n-1 << "\n" << 1 << "\n";
        return;
    }

    function<int(int)> func = [&](int win) -> int {
        int x = 1;
        int cnt = 0;
        while(x*2 <= win) {
            x<<=1; cnt++;
        }
        return cnt;
    };

    int dpt = func(n);
    vector<vector<int>> rgcd(dpt+1, vector<int>(n, -1));
    for(int i = 0 ; i<n ; i++) rgcd[0][i] = v[i];
    for(int win = 1 ; win <= dpt ; win++) {
        int temp = 1<<win;
        for(int pos = 0 ; pos + temp <= n ; pos++) {
            rgcd[win][pos] = gcd(rgcd[win-1][pos], rgcd[win-1][pos + temp/2]);
        }
        dbg(rgcd[win]);
    }
    vector<vector<int>> rmin(dpt+1, vector<int>(n, -1));
    for(int i = 0 ; i<n ; i++) rmin[0][i] = v[i];
    for(int win = 1 ; win<=dpt ; win++) {
        int temp = 1<<win;
        for(int pos = 0 ; pos + temp <= n ; pos++) {
            rmin[win][pos] = min(rmin[win-1][pos], rmin[win-1][pos + temp/2]);
        }
        dbg(rmin[win]);
    }

    dbg(rgcd);
    dbg(rmin);

    function<bool(int)> check = [&](int win) -> bool {
        int cnt = func(win);
        for(int i = 0 ; i<=n-win ; i++) {
            int gcd = std::gcd(rgcd[cnt][i], rgcd[cnt][win - (1<<cnt) + i]);
            int min = std::min(rmin[cnt][i], rmin[cnt][win - (1<<cnt) + i]);
            dbg(win, i, gcd, min, gcd == min);
            if(gcd == min) return true;
        }
        return false;
    };

    int l = 1, r = n;
    while(l+1 < r) {
        int mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;

    }
    
    int cnt = func(l);
    vector<int> res;
    for(int i = 0 ; i<=n-l ; i++) {
        int gcd = std::gcd(rgcd[cnt][i], rgcd[cnt][l - (1<<cnt) + i]);
        int min = std::min(rmin[cnt][i], rmin[cnt][l - (1<<cnt) + i]);
        dbg(i, l, gcd, min);
        if(gcd == min) {res.push_back(i);
        dbg(res);}
    }

    cout << res.size() << " " << l-1 << "\n";
    for(int num : res) cout << num + 1 << " ";
    cout << "\n";

}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    
    
****/

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    // cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


// ======= CHECKLIST =======
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)