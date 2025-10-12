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

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

void solve(int tc_no)
{
    
    cerr << "Case #" << tc_no << ":\n";
    int n;
    cin >> n;
    vector<int> v(n+1);

    for(int i = 1 ; i<=n ; i++) cin >> v[i];

    vector<int> inc(1, 0);
    for(int i = 1 ; i<=n ; i++) {
        if(inc.back() < v[i]) {
            inc.pb(v[i]);
        }
    }

    
    vector<int> dec(1, 0);
    for(int i = n ; i>0 ; i--) {
        if(dec.back() < v[i]) {
            dec.pb(v[i]);
        }
    }


    for(int num : inc) cerr << num << " ";
    cerr << "\n";
    for(int num : dec) cerr << num << " ";
    cerr << "\n";

    vector<vector<int>> pref(n+2, vector<int>(inc.size()));

    for(int i = 0 ; i<=n+1 ; i++) pref[i][0] = 1;

    cerr << "Pref:\n";
    for(int i = 1 ; i<=n ; i++) {
        int curr = v[i];
        cerr << curr << "\n";
        for(int j = 1 ; j<inc.size() ; j++) {
            if(curr == inc[j]) {
                pref[i][j] = add(pref[i-1][j-1], mul(pref[i-1][j], 2LL));
            } else if(curr < inc[j]) {
                pref[i][j] = add(pref[i-1][j], pref[i-1][j]);
            } else pref[i][j] = pref[i-1][j];
            cerr << pref[i][j] << " ";
        }
        cerr << "\n";
    }

    vector<vector<int>> suff(n+2, vector<int>(dec.size()));

    for(int i = 0 ; i<=n+1 ; i++) suff[i][0] = 1;

    cerr << "Suff:\n";
    for(int i = n ; i>=1 ; i--) {
        int curr = v[i];
        cerr << curr << "\n";
        for(int j = 1 ; j<dec.size() ; j++) {
            if(curr == dec[j]) {
                if(curr != dec.back()) suff[i][j] = add(suff[i+1][j-1], mul(suff[i+1][j], 2LL));
                else suff[i][j] = add(suff[i+1][j-1], suff[i+1][j]);
            } else if(curr < dec[j]) {
                suff[i][j] = add(suff[i+1][j], suff[i+1][j]);
            } else suff[i][j] = suff[i+1][j];
            cerr << suff[i][j] << " ";
        }
        cerr << "\n";
    }

    int ans = 0;
    for(int i = 1 ; i<=n ; i++) {
        int curr = v[i];
        if(curr == dec.back()) {
            ans = add(ans, mul(pref[i-1][inc.size()-2], suff[i][dec.size()-1]));    
        }
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

    // cerr << fixed;
    cerr << setprecision(10);

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