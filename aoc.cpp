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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> v;
    string s;
    while(cin >> s) v.pb(s);
    
    vector<int> pos = {0,0};
    vector<int> dir = {-1, 0};

    for(ll i = 0 ; i<v.size() ; i++)
        for(ll j = 0 ; j<v[i].length() ; j++)
            if(v[i][j] == '^')
            {
                // v[i][j] = '@';
                pos[0] = i;
                pos[1] = j;
            }
            else if(v[i][j] == '.')
                v[i][j] = ' ';
    

    while(true)
    {
        if(dir[0] == 0) v[pos[0]][pos[1]] = '-';
        else if(dir[1] == 0) v[pos[0]][pos[1]] = '|';
        if(pos[0] + dir[0] >= v.size() || pos[0] + dir[0] < 0 || pos[1] + dir[1] < 0 || pos[1] + dir[1] >= v[0].size())
            break;
        if(v[pos[0] + dir[0]][pos[1] + dir[1]] == '#')
        {
            if(dir[0] == 0 && dir[1] == 1) {dir[0] = 1 ; dir[1] = 0; }
            else if(dir[0] == 0 && dir[1] == -1) {dir[0] = -1 ; dir[1] = 0; }
            else if(dir[0] == 1 && dir[1] == 0) {dir[0] = 0 ; dir[1] = -1; }
            else if(dir[0] == -1 && dir[1] == 0) {dir[0] = 0 ; dir[1] = 1; }
            v[pos[0]][pos[1]] = '+';
            pos[0] = pos[0] + dir[0];
            pos[1] = pos[1] + dir[1];
        }
        else
        {
            pos[0] = pos[0] + dir[0];
            pos[1] = pos[1] + dir[1];
        }
    }

    ll count = 0;
    for(string s : v)
    {
        cout << s << "\n";
    }

    // cout << count << "\n";

    return 0;
}