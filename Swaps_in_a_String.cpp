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

void preprocessing()
{

    // Code here

}

void generate(vector<pair<int, int>> &vp, string &s)
{
    int n = s.length();
    int prev = 0;
    bool seen = false;
    for(int i = 1 ; i<n ; i++)
    {
        if(s[i] == 'C') seen = true;
        if(s[i] == 'A' && seen)
        {
            vp.pb(mpr(prev, i-1));
            prev = i;
            seen = false;
        }
    }
}

int deal_with(string &s, int l, int r)
{
    vector<int> a(r-l+1);

    int count = 0;
    int ops = 0;
    for(int i = l ; i<=r ; i++)
    {
        if(s[i] == 'C') count = 0;
        if(s[i] == 'A') count++;
        if(s[i] == 'B') ops += count;
        a[i-l] = ops;
    }

    vector<int> c(r-l+1);

    count = 0;
    ops = 0;
    for(int i = r ; i>=l ; i--)
    {
        if(s[i] == 'A') count = 0;
        if(s[i] == 'C') count++;
        if(s[i] == 'B') ops += count;
        c[i-l] = ops;
    }

    int ans = max(a[r-l], c[0]);
    for(int i = 0 ; i<r-l ; i++) ans = max(ans, a[i] + c[i+1]);

    return ans;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ":\n";
    int n;
    cin >> n;
    string s;
    s.pb('C');
    string temp; cin >> temp;
    for(char c : temp) s.pb(c);
    s.pb('A');
    s.pb('C');
    s.pb('A');
    
    int ans = 0;
    vector<pair<int, int>> segs;

    generate(segs, s);

    for(auto [l, r] : segs)
    {
        // cout << "Dealing with ";
        // for(int i = l ; i<=r ; i++) cout << s[i];
        // cout << "->";
        int x = deal_with(s, l, r);
        // cout << x << "\n";
        ans += x;
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}