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

const long double eps = 1e-12;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll n, w;
    cin >> n >> w;

    vector<pair<int, int>> blocks(n);
    for(pair<int, int> &p : blocks)
    {
        cin >> p.F >> p.S;
        p.F--;
        p.S--;
    }

    vector<priority_queue<int, vector<int>, greater<int>>> cols(w);
    
    map<pair<int, int>, int> data;
    for(pair<int, int> &p : blocks)
        cols[p.F].push(p.S);
    
    int count = 0;
    while(count < n)
    {
        int maxt = 0;
        for(int i = 0 ; i<w ; i++)
        {
            if(cols[i].empty()) maxt = INT_MAX;
            else maxt = max(maxt, cols[i].top());
        }
        for(int i = 0 ; i<w ; i++)
        {
            if(cols[i].empty()) continue;
            count++;
            data[mpr(i, cols[i].top())] = maxt+1;
            // cout << i+1 << " " << cols[i].top()+1 << " -> " << maxt+1 << "#\n";
            cols[i].pop();
            
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> b >> a;
        // cout << data[blocks[a-1]] << " " << b << " ";
        cout << (data[blocks[a-1]] <= b ? "No\n" : "Yes\n");
    }

    return 0;
}