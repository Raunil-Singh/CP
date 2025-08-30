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
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<string> v(2);
    cin >> v[0] >> v[1];

    for(ll i = 0 ; i<n ; i++)
    {
        if(v[0][i] == '.')
        {
            if(v[1][i] == '#')
            {
                if(i+1<n && v[0][i+1] == '.')
                {
                    v[0][i] = '#';
                    v[0][i+1] = '#';
                }
                else {cout << "None\n"; return;}
            }
            else if(i>=n-1 || v[0][i+1] == '#')
            {
                v[0][i] = '#';
                v[1][i] = '#';
            }
        }
        if(v[1][i] == '.')
        {
            if(v[0][i] == '#')
            {
                if(i+1<n && v[1][i+1] == '.')
                {
                    v[1][i] = '#';
                    v[1][i+1] = '#';
                }
                else {cout << "None\n"; return;}
            }
            else if(i>=n-1 || v[1][i+1] == '#')
            {
                v[1][i] = '#';
                v[0][i] = '#';
            }
        }
        if(v[0][i] == '.' && v[1][i] == '.') i++;
    }
    for(ll i = n-1 ; i>=0 ; i--)
    {
        if(v[0][i] == '.')
        {
            if(v[1][i] == '#')
            {
                if(i>0 && v[0][i-1] == '.')
                {
                    v[0][i] = '#';
                    v[0][i-1] = '#';
                }
                else {cout << "None\n"; return;}
            }
            else if(i<=0 || v[0][i-1] == '#')
            {
                v[0][i] = '#';
                v[1][i] = '#';
            }
        }
        if(v[1][i] == '.')
        {
            if(v[0][i] == '#')
            {
                if(i>0 && v[1][i-1] == '.')
                {
                    v[1][i] = '#';
                    v[1][i-1] = '#';
                }
                else {cout << "None\n"; return;}
            }
            else if(i<=0 || v[1][i-1] == '#')
            {
                v[1][i] = '#';
                v[0][i] = '#';
            }
        }
        if(v[0][i] == '.' && v[1][i] == '.') i--;
    }
    for(ll i = 0 ; i<n ; i++)
    {
        if(v[0][i] == '.' || v[1][i] == '.')
        {
            cout << "Multiple\n";
            return;
        }
    }
    cout << "Unique\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
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