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

    int n{1000};
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, INT_MAX));
    g[0][0] = 0;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(mpr(0,0));

    vector<int> val = {-2, -1, 1, 2};

    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int x = p.S/n, y = p.S%n, dist = p.F;
        if(g[x][y] < dist) continue;
        for(int i = 0 ; i<val.size() ; i++)
        {
            int j = 3 - abs(val[i]);
            if((0 <= x + val[i] && x + val[i] < n) && (0 <= y + j && y + j < n) && g[x + val[i]][y + j] > dist+1)
            {
                pq.push(mpr(dist + 1, n*(x + val[i]) + y + j));
                g[x + val[i]][y + j] = dist + 1;
            }
            j *= -1;
            if((0 <= x + val[i] && x + val[i] < n) && (0 <= y + j && y + j < n) && g[x + val[i]][y + j] > dist+1)
            {
                pq.push(mpr(dist + 1, n*(x + val[i]) + y + j));
                g[x + val[i]][y + j] = dist + 1;
            }
        }
    }

    for(vector<int> &v : g)
    {
        for(int &num : v) cout << num << " ";
        cout << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 

    return 0;
}