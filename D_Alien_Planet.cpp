// B87678

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
#define MOD 1000000007

vector<int> val;
vector<int> c3;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

void preprocessing()
{

    // Code here
    val.assign(40, 0);
    c3.assign(40, 0);
    vector<int> d(40), p(40), a(40);
    d[0] = 1;
    for(int i = 1 ; i<40 ; i++) {
        d[i] = add(d[i-1], p[i-1]);
        p[i] = a[i-1];
        a[i] = d[i];
        val[i] = add(d[i], p[i]);
        while(val[i] % 3 == 0) {
            val[i] /= 3;
            c3[i]++;
        }
        // cout << d[i] << " " << p[i] << " " << a[i] << " " << val[i] << " " << c3[i] << "***\n";
    }

}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int k;
    cin >> k;

    if(k == 1) {
        cout << 1 << "\n";
        return;
    }

    int bc = 0;
    k/=2;

    int prev = 0;
    vector<vector<int>> x(2);
    int cnt = 0;
    while(k) {
        bc++;
        // cout << k%2 << " ";
        if(prev == k%2) {
            cnt++;
        } else if(cnt) {
            x[prev].push_back(cnt);
            cnt = 1;
        }
        prev = k%2;
        k/=2;
    }

    // cout << "\n";

    x[1].push_back(cnt);

    int p = 1;
    int q = bc;
    // cout << q << "\n";
    for(int i = 0 ; i<x[0].size() ; i++) {
        p = mul(p, val[x[0][i]]);
        q -= c3[x[0][i]];
        // cout << p << " ";
    }
    // cout << "\n";
    while(q < 0) {
        p = mul(p, 3LL);
        q++;
    }
    // cout << q << "\n";
    // cout << p << " " << q << " ";
    cout << add(p, q) << "\n";

    
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