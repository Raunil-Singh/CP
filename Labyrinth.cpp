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

    ll n, m;
    cin >> n >> m;
    vector<string> v(n); inp(v);

    pair<int, int> st = {0,0}, end = {0,0};
    for(ll i = 0 ; i<n ; i++)
    {
        for(ll j = 0 ; j<m ; j++)
        {
            if(v[i][j] == 'A')
            {
                st.F = i;
                st.S = j;
            }
            else if(v[i][j] == 'B')
            {
                end.F = i;
                end.S = j;
            }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push(st);

    dist[st.F][st.S] = 0;

    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        if(curr.F+1<n && v[curr.F+1][curr.S]!='#' && dist[curr.F+1][curr.S]>dist[curr.F][curr.S]+1)
        {
            dist[curr.F+1][curr.S] = dist[curr.F][curr.S]+1;
            q.push(mpr(curr.F+1, curr.S));
        }
        if(curr.F-1>=0 && v[curr.F-1][curr.S]!='#' && dist[curr.F-1][curr.S]>dist[curr.F][curr.S]+1)
        {
            dist[curr.F-1][curr.S] = dist[curr.F][curr.S]+1;
            q.push(mpr(curr.F-1, curr.S));
        }
        if(curr.S+1<m && v[curr.F][curr.S+1]!='#' && dist[curr.F][curr.S+1]>dist[curr.F][curr.S]+1)
        {
            dist[curr.F][curr.S+1] = dist[curr.F][curr.S]+1;
            q.push(mpr(curr.F, curr.S+1));
        }
        if(curr.S-1>=0 && v[curr.F][curr.S-1]!='#' && dist[curr.F][curr.S-1]>dist[curr.F][curr.S]+1)
        {
            dist[curr.F][curr.S-1] = dist[curr.F][curr.S]+1;
            q.push(mpr(curr.F, curr.S-1));
        }
    }

    if(dist[end.F][end.S] == INT_MAX)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    string res = "";
    while(end.F!=st.F || end.S!=st.S)
    {
        if(end.F-1>=0 && dist[end.F-1][end.S]<dist[end.F][end.S])
        {
            end.F--;
            res.pb('D');
        }
        else if(end.S-1>=0 && dist[end.F][end.S-1]<dist[end.F][end.S])
        {
            end.S--;
            res.pb('R');
        }
        else if(end.F+1<n && dist[end.F+1][end.S]<dist[end.F][end.S])
        {
            end.F++;
            res.pb('U');
        }
        else if(end.S+1<m && dist[end.F][end.S+1]<dist[end.F][end.S])
        {
            end.S++;
            res.pb('L');
        }
    }

    reverse(all(res));

    cout << res.size() << "\n" << res << "\n";

    return 0;
}