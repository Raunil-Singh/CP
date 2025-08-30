#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define MOD 1000000007LL

int add(int a, int b) {
    return ((a%MOD) + (b%MOD)) % MOD;
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

    // code here
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> vp(n);
    for(int i = 0 ; i<n ; i++) {
        int a, b;
        cin >> a >> b;
        vp[i] = mpr(a, b);
    }

    sort(all(vp));

    int ans = 0;
    ordered_set<int> os;
    int factor = 1000000001LL;

    for(auto p : vp) {
        int st = p.F, en = p.S;
        int target = os.order_of_key(st * factor) - 1;
        if(target == -1 || (st - *os.find_by_order(target)/factor) * y >= x) {
            os.insert(en * factor + st);
        } else {
            int number = *os.find_by_order(target) % factor;
            os.erase(os.find_by_order(target));
            os.insert(en*factor + number);
        }
    }

    int cost = 0;
    for(int num : os) {
        int st = num % factor, en = num / factor;
        cost = add(cost, add(x, y * (en - st)));
    }

    cout << cost << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}