// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]

vector<pair<ll,ll>> do_dfs(int r, int c, vector<string> &v, int p1, int p2, ll dir, ll mc)
{
    set<pair<ll,ll>> seen;
    ll x1 = p1, y1 = p2;
    ll dir1 = 0, dir2 = dir;
    for(ll i = 0 ; i<2*r*c ; i++)
    {
        if(x1<0 || y1<0 || x1>=r || y1>=c)
        {
            goto SAFETY1;
        }
        else if(v[x1][y1] == '/')
        {
            seen.insert(make_pair(x1, y1));
            if(dir1 == 0)
            {
                dir1 = -dir2;
                dir2 = 0;
            }
            else
            {
                dir2 = -dir1;
                dir1 = 0;
            }
        }
        else if(v[x1][y1] == '\\')
        {
            seen.insert(make_pair(x1, y1));
            swap(dir1, dir2);
        }
        x1 += dir1;
        y1 += dir2;
    }
    return {};
    SAFETY1:;

    ll x2 = p1, y2 = p2;
    dir1 = (v[p1][p2] == '/' ? dir : -dir), dir2 = 0;
    for(ll i = 0 ; i<2*r*c ; i++)
    {
        if(x2<0 || y2<0 || x2>=r || y2>=c)
        {
            goto SAFETY2;
        }
        else if(v[x2][y2] == '/')
        {
            seen.insert(make_pair(x2, y2));
            if(dir1 == 0)
            {
                dir1 = -dir2;
                dir2 = 0;
            }
            else
            {
                dir2 = -dir1;
                dir1 = 0;
            }
        }
        else if(v[x2][y2] == '\\')
        {
            seen.insert(make_pair(x2, y2));
            swap(dir1, dir2);
        }
        x2 += dir1;
        y2 += dir2;
    }
    return {};
    SAFETY2:;

    if(((ll)seen.size()) == mc)
    {
        return {{x1, y1}, {x2, y2}};
    }

    return {};

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll r, c;
    cin >> r >> c;

    vector<string> v(r); inp(r, v);
    
    ll p1, p2;
    ll mc = 0;
    for(ll i = 0 ; i<r ; i++)
        for(ll j = 0 ; j<c ; j++)
        {
            if(v[i][j] == '\\' || v[i][j] == '/')
            {
                if(mc == 0)
                {
                    p1 = i;
                    p2 = j;
                }
                mc++;
            }
        }

    if(mc == 0)
    {
        cout << 2*(r+c) << "\n";
        for(ll i = 1 ; i<=r ; i++)
        {
            cout << "E" << i << " W" << i << " ";
        }
        for(ll i = 1 ; i<=c ; i++)
        {
            cout << "N" << i << " S" << i << " ";
        }
        cout << "\n";
        return 0;
    }

    vector<pair<ll,ll>> res1 = do_dfs(r, c, v, p1, p2, 1, mc);
    vector<pair<ll,ll>> res2 = do_dfs(r, c, v, p1, p2, -1, mc);

    cout << res1.size() + res2.size() << "\n";
    if(res1.size() + res2.size())
    {
        for(pair<ll, ll> p : res1)
        {
            if(p.F < 0) cout << "N" << p.S+1 << " ";
            if(p.S < 0) cout << "W" << p.F+1 << " ";
            if(p.F >= r) cout << "S" << p.S+1 << " ";
            if(p.S >= c) cout << "E" << p.F+1 << " ";
        }
        
        for(pair<ll, ll> p : res2)
        {
            if(p.F < 0) cout << "N" << p.S+1 << " ";
            if(p.S < 0) cout << "W" << p.F+1 << " ";
            if(p.F >= r) cout << "S" << p.S+1 << " ";
            if(p.S >= c) cout << "E" << p.F+1 << " ";
        }
        cout << "\n";
    }


    return 0;
}