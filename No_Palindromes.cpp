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
    
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    set<char> odd;
    set<char> even;
    for(char c: s)
    {
        if(odd.find(c)!=odd.end())
        {
            odd.erase(c);
            even.insert(c);
        }
        else
        {
            even.erase(c);
            odd.insert(c);
        }
    }
    
    // cout << "Even : ";
    // for(char c : even) cout << c << " ";
    // cout << "#\n";
    // cout << "Odd : ";
    // for(char c : odd) cout << c << " ";
    // cout << "#\n";
    
    if(odd.size() + even.size()==1) // Verified
    {
        cout << "-1\n";
        return;
    }
    if(odd.size()>=2) // Verified
    {
        cout << "0\n";
        return;
    }
    if(odd.size()==1) // Verified
    {
        cout << "1\n";
        cout << (*even.begin()) << "\n";
        return;
    }
    if(odd.size()==0)
    {
        cout << "2\n";
        string eve = "";
        for(char c : s)
            if(even.find(c)!=even.end()) eve.pb(c);
        vector<pair<char, int>> v;
        for(ll i = 0 ; i<eve.size() ; i++)
            v.pb(mpr(eve[i], -i));
        sort(all(v));
        ll pos = 1;
        while(v[pos].F == v[pos-1].F) pos++;
        string res = "";
        if(v[pos].S > v[pos-1].S)
        {
            res.pb(v[pos].F);
            res.pb(v[pos-1].F);
        }
        else 
        {
            res.pb(v[pos-1].F);
            res.pb(v[pos].F);
        }

        // cout << res << "#";

        ll curr = 1-v[pos-1].S;
        char minc = 'z'+1;
        while(curr < eve.size())
        {
            if(even.find(eve[curr])!=even.end() && eve[curr]!=v[0].F) minc = min(minc, eve[curr]);
            curr++;
        }

        if(minc <= 'z') cout << v[0].F << minc << "\n";
        else cout << res << "\n";
        return;
    }
    
}

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
        solve(i);

    return 0;
}