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
    vector<string> v(n); inp(n, v);
    x--;
    y--;

    string dir; cin >> dir;

    ll count = 0;
    if(v[x][y] == '@')
    {
        count++;
        v[x][y] = '.';
    }
    for(char c : dir)
    {
        switch(c)
        {
            case 'U':
            {
                if(x-1>=0 && v[x-1][y] != '#') x--;
            } break;
            case 'D':
            {
                if(x+1<n && v[x+1][y] != '#') x++;
            } break;
            case 'L':
            {
                if(y-1>=0 && v[x][y-1] != '#') y--;
            } break;
            case 'R':
            {
                if(y+1<m && v[x][y+1] != '#') y++;
            } break;
        }
        if(v[x][y] == '@')
        {
            count++;
            v[x][y] = '.';
        }
    }
    
    cout << x+1 << " " << y+1 << " " << count << "\n";

    return 0;
}