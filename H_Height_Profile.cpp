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

void solve(vector<int> h, int inc) {
    int n = h.size();
    for(int i = 0 ; i<n ; i++) h[i] -= i*inc;
    priority_queue<pair<int, int>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    set<int> seen;
    for(int i = 0 ; i<n ; i++) {
        pq.push(mpr(h[i], i));
        pq2.push(mpr(h[i], i));
    }
    bool flag = false;
    double ans = 0;
    while(!pq.empty()) {
        auto p = pq.top();
        int height = p.first, ind = p.second;
        pq.pop();
        seen.insert(ind);
        int back = *seen.rbegin();
        if(back <= ind) continue;
        flag = true;
        ans = max(ans, (double)(back - ind));
        if(back < n-1 && h[back+1] <= height)
            ans = max(ans, ((double)(height - back*h[back+1] - h[back]*(back+1)))/(h[back+1] - h[back]));
        cout << ans << " ";
    }
    cout << "#\n";
    seen.clear();
    while(!pq2.empty()) {
        auto p = pq2.top();
        int height = p.first, ind = p.second;
        pq2.pop();
        seen.insert(ind);
        int front = *seen.begin();
        if(front >= ind) continue;
        flag = true;
        ans = max(ans, (double)(ind - front));
        if(h[front+1] <= height)
            ans = max(ans, ((double)(height - (h[front] + (h[front] - h[front+1])*front)))/(h[front+1] - h[front]));
        cout << ans << " ";
    }
    cout << "#\n";

    if(flag) cout << ans << "\n";
    else cout << "-1\n";

}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, k;
    cin >> n >> k;
    vector<int> h(n+1); inp(h);

    while(k--)
    {
        int real, fraction;
        scanf("%lld.%lld", &real, &fraction);
        
        solve(h, real*10 + fraction);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}