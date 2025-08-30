// 02-06-2025 11:20:24 (IST +0530)
// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

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

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

vector<vector<int>> facts;

void preprocessing()
{

    int cnt = 100000;
    facts = vector<vector<int>>(cnt+1);
    for(int i = 2 ; i<=cnt ; i++)
        for(int j = i ; j<=cnt ; j+=i)
            facts[j].pb(i);

}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n, q;
    cin >> n >> q;
    vector<int> a(n); inp(a);

    map<int, vector<int>> mpp;
    for(int i = 0 ; i<n ; i++)
        mpp[a[i]].pb(i);
    
    for(int _ = 0 ; _<q ; _++)
    {
        int k, l, r;
        cin >> k >> l >> r;
        vector<int> ind;
        for(int num : facts[k])
        {
            int pos = lower_bound(all(mpp[num]), l-1) - mpp[num].begin();
            if(pos < mpp[num].size())
                if(mpp[num][pos] < r) ind.pb(mpp[num][pos]);
        }
        sort(all(ind));
        ind.pb(r);
        int curr = l-1;
        int ans = 0;
        for(int i : ind)
        {
            ans += k*(i-curr);
            curr = i;
            if(i<n) while(k%a[i] == 0) k/=a[i];
        }
        cout << ans << "\n";
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

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}