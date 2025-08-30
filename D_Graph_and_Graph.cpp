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

class Solution
{
private :

    vector<vector<int>> adj1, adj2;
    int n;
    int x1, x2;

public :
    void solve(ll tc_no)
    {
        
        cin >> n >> x1 >> x2;
        x1--;
        x2--;
        adj1.assign(n, vector<int>());
        adj2.assign(n, vector<int>());

        int m1; cin >> m1;

        for(int i = 0 ; i<m1 ; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj1[a].pb(b);
            adj1[b].pb(a);
        }

        int m2; cin >> m2;

        for(int i = 0 ; i<m2 ; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj2[a].pb(b);
            adj2[b].pb(a);
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push(mpr(0, mpr(x1, x2)));
        
        vector<vector<int>> costs(n, vector<int>(n, INT_MAX));

        set<int> s;
        
        while(!pq.empty())
        {
            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();
            if(costs[curr.S.F][curr.S.S] <= curr.F) continue;
            costs[curr.S.F][curr.S.S] = curr.F;
            for(int next1 : adj1[curr.S.F])
                for(int next2 : adj2[curr.S.S])
                {
                    pq.push(mpr(abs(next1-next2) + curr.F, mpr(next1, next2)));
                    if(curr.S.F == curr.S.S && next1 == next2)
                    {
                        s.insert(curr.S.F);
                        // cout << curr.S.F << ' ' << next1 << " !!\n";
                    }
                }
        }

        int ans = INT_MAX;
        for(int i : s)
        {
            // cout << i << " @\n";
            ans = min(ans, costs[i][i]);
            // cout << costs[i][i] << " " << i+1 << "!!\n";
        }
        if(ans == INT_MAX) ans = -1;

        cout << ans << "\n";

    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(i);
    }
    return 0;
}