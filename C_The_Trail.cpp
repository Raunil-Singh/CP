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

void solve(ll tc_no)
{
    
    ll n, m;
    cin >> n >> m;
    string s; cin >> s;

    vector<vector<int>> grid(n, vector<int>(m));
    for(vector<int> &v : grid) inp(v);

    vector<int> choice(n+m-1);

    for(ll i = 0 ; i<n+m-2 ; i++)
        choice[i] = (s[i]=='R');
    choice[n+m-2] = 0;

    vector<vector<int>> path(n, vector<int>(m, false));
    pair<int, int> pos = mpr(0,0);
    path[pos.F][pos.S] = true;
    vector<pair<int, int>> cells;
    for(ll i = 0 ; i<s.length() ; i++)
    {
        if(s[i] == 'D') pos.F++;
        else pos.S++;
        path[pos.F][pos.S] = true;
        cells.pb(pos);
    }

    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for(ll i = 0 ; i<n ; i++)
    {
        for(ll j = 0 ; j<m ; j++)
        {
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }
    }

    ll l = -(1000000000000000000LL), r = 1000000000000000000LL;
    while(l<r)
    {
        // cout << l << " " << r << " # \n";
        vector<int> r_ = row, c_ = col;
        ll x = l + (r-l)/2;
        for(pair<int, int> p : cells)
        {
            // cout << "**";
            ll val = x-(choice[p.F+p.S] ? c_[p.S] : r_[p.F]);
            if(val > 1000000000000000LL)
            {
                // cout << val << " $ ";
                r = x-1;
                goto NEXT;
            }
            else if(val < -1000000000000000LL)
            {
                cout << val << " $ ";
                l = x+1;
                goto NEXT;
            }
            if(choice[p.F+p.S]) c_[p.S] += val;
            else r_[p.F] +=  val;
        }
        l = x;
        break;
        NEXT:;
    }

    ll val = l;

    for(ll i = 0 ; i<n ; i++)
    {
        for(ll j = 0 ; j<m ; j++)
        {
            if(!path[i][j]) continue;
            if(choice[i+j]) grid[i][j] += val - col[j];
            else grid[i][j] += val - row[i];
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }
    }

    for(ll i = 0 ; i<n ; i++)
    {
        for(ll j = 0 ; j<m ; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}