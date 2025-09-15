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
    
    // cout << "Case #" << tc_no << ":\n";
    int n;
    cin >> n;
    int L = 0;
    vector<vector<int>> v(n);
    for(int i = 0 ; i<n ; i++) {
        int len;
        cin >> len;
        L = max(L, len);
        v[i].pb(len);
        while(len--) {
            int x; cin >> x;
            v[i].pb(x);
        }
    }

    sort(all(v));
    // for(vector<int> &temp : v) {
    //     for(int num : temp) cout << num << " ";
    //     cout << '\n';
    // }

    set<int> valid;
    for(int i = 0 ; i<n ; i++) valid.insert(i);
    int st = 0;
    for(int i = 1 ; i<=L ; i++) {

        if(valid.size() == 0 || v[*valid.begin()][0] < i) {
            while(v[st][0] < i) st++;
            for(int j = st ; j<n ; j++) valid.insert(j);
            while(v[*valid.begin()][0] < i) valid.erase(*valid.begin());
        }

        int min_el = INT_MAX;
        for(int num : valid) {
            min_el = min(min_el, v[num][i]);
            // cout << v[num][i] << ":" << num << " , ";
        }
        // cout << "\n";
        for(auto it = valid.begin() ; it != valid.end() ; ) {
            auto next = it;
            next++;
            if(v[*it][i] != min_el) valid.erase(*it);
            it = next;
        }
        cout << min_el << " ";
        // cout << min_el << ":" << valid.size() << ":" << st << " ";
    }
    cout << "\n";
    
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