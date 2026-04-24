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
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(n); inp(v);
    string s;
    cin >> s;

    bool flag = (s[0] == '0' && s[n-1] == '0');
    // cout << flag <<  " ";
    for(int i = 1 ; i<n-1 ; i++) {
        if((v[i] == 1 && s[i] == '1') || (v[i] == n && s[i] == '1')) flag = false;
        // cout << flag << " ";
    }
    // cout << "\n";


    if(!flag) cout << "-1\n";
    else {
        int a = 1, b = 1;
        for(int i = 0 ; i<n ; i++) {
            if(v[i] == 1) a = i+1;
            else if(v[i] == n) b = i+1;
        }
        if(a > b) swap(a, b);
        cout << 5 << "\n"; 
        cout << 1 << " " << a << "\n";
        cout << 1 << " " << b << "\n";
        cout << a << " " << n << "\n";
        cout << a << " " << b << "\n";
        cout << b << " " << n << "\n";
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

    int t;
    cin >> t;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}