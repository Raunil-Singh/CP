// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
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

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, m;
    cin >> n >> m;
    vector<int> v(n); inp(v);

    int ans{};
    map<int, int> mp;
    for(int i = 0 ; i<n ; i++)
    {
        if(mp.find(v[i]-1) == mp.end()) ans++;
        mp[v[i]] = i+1;
    }

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        if(a>b) swap(a, b);
        int n1 = v[a-1], n2 = v[b-1];
        swap(v[a-1], v[b-1]);
        mp[n1] = b;
        mp[n2] = a;
        if(n1+1 == n2) ans++;
        else if(n1-1 == n2) ans--;
        if(mp[n1+1] > a && mp[n1+1] < b) ans++;
        if(mp[n1-1] > a && mp[n1-1] < b) ans--;
        
        if(mp[n2+1] > a && mp[n2+1] < b) ans--;
        if(mp[n2-1] > a && mp[n2-1] < b) ans++;
        cout << ans << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}