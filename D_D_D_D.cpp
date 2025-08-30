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

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void preprocessing()
{

    // Code here

}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n, m, l;
    cin >> n >> m >> l;

    int min_odd = INT_MAX;
    int sum = 0;
    for(int i = 0 ; i<l ; i++){
        int num; cin >> num;
        sum += num;
        if(num&1) min_odd = min(min_odd, num);
    }

    vector<vector<int>> dist(n+1, vector<int>(2, INT_MAX));

    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i<m ; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    // dist[1][0] = 0;

    queue<int> q; // (node, dist)
    q.push(1);

    for(int x = 0 ; x<=sum && q.size() ; x++)
    {
        int sze = q.size();
        while(sze--)
        {
            int curr = q.front();
            q.pop();
            if(dist[curr][x&1] < x) goto NEXT2;
            dist[curr][x&1] = x;
            for(int next : adj[curr])
            {
                if(dist[next][(x+1)&1] <= x) goto NEXT1;
                q.push(next);
                NEXT1:;
            }
            NEXT2:;
        }
    }

    int d1 = sum, d2 = max(sum - min_odd, (sum&1LL) ? -2LL : -1LL);
    // cout << d1 << " " << d2 << "##\n";
    for(int i = 1 ; i<=n ; i++)
        if((dist[i][d1&1LL] <= d1) || (dist[i][(d2 + 4)&1LL] <= d2)) cout << "1";
        else cout << "0";
    cout << "\n";

    // for(int i = 0 ; i<=1 ; i++)
    // {
    //     for(int j = 1 ; j<=n ; j++)
    //         cout << dist[j][i] << " ";
    //     cout << "#\n";
    // }

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}