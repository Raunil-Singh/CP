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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<pair<int, int>> v(n);
    for(ll i = 0 ; i<n ; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    map<int, vector<pair<int, int>>> pathX;
    map<int, vector<pair<int, int>>> pathY;
    for(ll i = 0 ; i<m ; i++)
    {
        char c;
        ll dist;
        cin >> c >> dist;
        switch(c)
        {
            case 'U':
            {
                pathY[x].pb(make_pair(y, y+dist));
                y += dist;
            } break;
            case 'D':
            {
                pathY[x].pb(make_pair(y-dist, y));
                y -= dist;
            } break;
            
            case 'R':
            {
                pathX[y].pb(make_pair(x, x+dist));
                x += dist;
            } break;
            case 'L':
            {
                pathX[y].pb(make_pair(x-dist, x));
                x -= dist;
            } break;
        }
    }

    cout << x << " " << y << " ";

    map<int, vector<pair<int, int>>> px;
    for(auto [a, b] : pathX)
    {
        sort(b.begin(), b.end());
        vector<pair<int, int>> path;
        pair<int,int> curr = {b[0].F, b[0].S};
        for(pair<int, int> p : b)
        {
            if(p.F <= curr.S)
            {
                curr.S = max(p.S, curr.S);
            }
            else
            {
                path.pb(curr);
                curr = p;
            }
        }
        path.pb(curr);
        px[a] = path;
    }

    map<int, vector<pair<int, int>>> py;
    for(auto [a, b] : pathY)
    {
        sort(b.begin(), b.end());
        vector<pair<int, int>> path;
        pair<int,int> curr = {b[0].F, b[0].S};
        for(pair<int, int> p : b)
        {
            if(p.F <= curr.S)
            {
                curr.S = max(p.S, curr.S);
            }
            else
            {
                path.pb(curr);
                curr = p;
            }
        }
        path.pb(curr);
        py[a] = path;
    }

    ll count = 0;
    for(pair<int, int> p : v)
    {
        x = p.F;
        y = p.S;
        vector<pair<int, int>> vec = px[y];

        ll l = 0, r = vec.size();
        while(l+1<r)
        {
            ll mid = (l+r)>>1;
            if(vec[mid].F <= x) l = mid;
            else r = mid;
        }
        if(vec.size() > 0 && vec[l].F <= x && vec[l].S>=x)
        {
            count++;
            goto NEXT_ITR;
        }
        
        vec = py[x];

        l = 0;
        r = vec.size();
        while(l+1<r)
        {
            ll mid = (l+r)>>1;
            if(vec[mid].F <= y) l = mid;
            else r = mid;
        }
        if(vec.size() > 0 && vec[l].F <= y && vec[l].S>=y)
        {
            count++;
            goto NEXT_ITR;
        }
        NEXT_ITR:;
    }

    cout << count << "\n";
    
    return 0;
}