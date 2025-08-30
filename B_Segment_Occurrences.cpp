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

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, m, q;
    cin >> n >> m >> q;

    string s, t;
    cin >> s >> t;

    vector<int> cnt(n+1);
    int prev = 0;
    for(int i = 0 ; i<n-m+1 ; i++)
    {
        bool flag = true;
        for(int j = 0 ; j<m && flag ; j++)
            if(s[i+j] != t[j]) flag = false;
        cnt[i+1] = prev;
        if(flag) cnt[i+1]++;
    }

    for(int i = 1 ; i<=n ; i++) cnt[i] += cnt[i-1];
    
    // for(int i = 0 ; i<=n ; i++) cout << i << ":" << cnt[i] << " " ;
    // cout << "##\n";

    for(int i = 0 ; i<q ; i++)
    {
        int l, r;
        cin >> l >> r;
        
        int ans = max(0LL, r >= m-1 ? cnt[r - m + 1] - cnt[l-1] : 0LL);
        // if(r >= m-1) cout << cnt[l-1] << " " << cnt[r-m+1] << " ";
        cout << ans << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}