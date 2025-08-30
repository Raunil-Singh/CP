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

bool compute(int x, int y) {
    // cout << x << " " << y << "\n";
    vector<int> bx, by;
    while(x) {
        bx.push_back(x&1);
        x >>= 1;
    }
    while(y) {
        by.push_back(y&1);
        y >>= 1;
    }
    if(by.size() < bx.size() || (by.size() - accumulate(all(by), 0LL) != bx.size() - accumulate(all(bx), 0LL))) {
        return false;
    }

    // for(int num : bx) cout << num; cout << "\n";
    // for(int num : by) cout << num; cout << "\n";


    for(int i = 0 ; i<=by.size() - bx.size() ; i++) {
        for(int j = 0 ; j<bx.size() ; j++) {
            if(bx[j] != by[i+j]) goto FLAG1;
        }
        return true;
        FLAG1:;
    }

    reverse(all(by));
    for(int i = 0 ; i<=by.size() - bx.size() ; i++) {
        for(int j = 0 ; j<bx.size() ; j++) {
            if(bx[j] != by[i+j]) goto FLAG2;
        }
        return true;
        FLAG2:;
    }

    return false;
}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int x, y;
    cin >> x >> y;

    if(x == y) {
        cout << "YES\n";
        return;
    } else if(y > 0 && y%2 == 0) {
        cout << "NO\n";
        return;
    }

    int a = x;
    while(x%2 == 0 && x > 0) x/=2;

    if(compute(x, y) || compute(a*2 + 1, y)) cout << "YES\n";
    else cout << "NO\n";

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

    int t = 1;
    // cin >> t;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}