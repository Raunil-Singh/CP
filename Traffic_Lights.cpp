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

    int l = 8, n = 3;
    cin >> l >> n;

    vector<int> v(n);
    inp(v);

    priority_queue<pair<int, int>> pq;
    pq.push(mpr(l, 0LL));
    ordered_set os;
    os.insert(0);
    os.insert(l);

    for(int num : v)
    {
        int pos = os.order_of_key(num);
        int n1 = *os.find_by_order(pos-1), n2 = *os.find_by_order(pos);
        os.insert(num);
        pq.push(mpr(num - n1, n1));
        pq.push(mpr(n2 - num, num));
        
        bool done = false;
        while(!done)
        {
            auto [len, start] = pq.top();
            // pair<int, int> p = pq.top();
            // int len = p.F, start = p.S;
            int p1 = os.order_of_key(start), p2 = os.order_of_key(start + len);
            if(p2-p1 == 1)
            {
                cout << len << " ";
                done = true;
            }
            else
                pq.pop();
        }
    }

    cout << "\n";
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}