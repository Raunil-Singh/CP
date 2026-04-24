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

#define int int64_t // upto 9.2 * (10^18)
#define uint uint64_t // upto 1.8 * (10^19)
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

void preprocessing() {

    // Code here

}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n{}, m{}, l{}, x{}, y{};
    cin >> n >> m >> l >> x >> y;

    vector<double> ans(m);

    vector<pair<int,int>> vpp;
    
    for(int i{} ; i<n ; i++) {
        int a{}, b{};
        cin >> a >> b;
        vpp.push_back(make_pair(a, b));
    }

    vector<pair<int,int>> bus_label(n);
    for(int i {} ; i<n ; i++) {
        bus_label[i] = make_pair(vpp[i].first, i);
    }

    sort(all(bus_label));

    vector<pair<int,int>> pass(m);
    for(int i{} ; i<m ; i++) {
        int a{};
        cin >> a;
        pass[i] = make_pair(a, i);
    }

    sort(all(pass));

    int curr_bus = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> time; // time, last valid

    for(auto [p, i] : pass) {
        ans[i] = (l-p*1.0)/((double)y);

        while(!time.empty() && time.top().second < p) time.pop();
        while(curr_bus < bus_label.size() && bus_label[curr_bus].first <= p) {
            time.push(make_pair((l-vpp[bus_label[curr_bus].second].second)/((double)y)+(vpp[bus_label[curr_bus].second].second-vpp[bus_label[curr_bus].second].first)/((double)x), vpp[bus_label[curr_bus].second].second));
            curr_bus++;
        }
        if(time.size())
            ans[i] = min(ans[i], time.top().first);
    }

    for(double x : ans) cout << x << "\n";
    
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    // cin >> t;
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}