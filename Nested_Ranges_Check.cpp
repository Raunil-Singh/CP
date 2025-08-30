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

bool comparator(const pair<int , int> &a, const pair<int , int> &b)
{
    if(a.F < b.F) return true;
    else if(a.F == b.F && a.S > b.S) return true;
    else return false;
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

    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(pair<int, int> &p : vp) cin >> p.F >> p.S;

    vector<pair<int, int>> cpy = vp;
    sort(all(cpy), comparator);

    map<pair<int, int>, int> mpp1;
    priority_queue<pair<int, int>> pq;
    for(pair<int, int> &p : cpy)
    {
        auto [a, b] = p;
        while(!pq.empty() && pq.top().F >= b)
        {
            auto [c, d] = pq.top(); pq.pop();
            mpp1[mpr(d, c)] = 1;
        }
        pq.push(mpr(b, a));
    }

    for(pair<int, int> p : vp) cout << mpp1[p] << " ";
    cout << "\n";

    map<pair<int, int>, int> mpp2;
    int upper = -1;
    for(pair<int, int> &p : cpy)
    {
        mpp2[p] = max(mpp2[p], (ll)(p.S <= upper));
        upper = max(upper, p.S);
    }

    for(pair<int, int> p : vp) cout << mpp2[p] << " ";
    cout << "\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}