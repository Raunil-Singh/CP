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

int n;
int cnt[100020][3];
int dp[100020][8];

void solve(int tc_no)
{
    cin >> n;
    for(int i = 0 ; i<3 ; i++)
        for(int j = 1 ; j<=n ; j++)
            cin >> cnt[j][i];

    for(int i = 1 ; i<=n ; i++) {
        for(int mask = 1 ; mask < 8 ; mask++) {
            dp[i][mask] = dp[i-1][mask];
            for(int j = 0 ; j<3 ; j++) {
                if(mask & (1<<j)) {
                    int temp = mask - (1<<j);
                    dp[i][mask] = max(dp[i][mask], dp[i-1][temp] + cnt[i][j]);
                }
            }
        }
    }

    cout << dp[n][7] << "\n";
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