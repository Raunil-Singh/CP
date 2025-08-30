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

bool verify(vector<vector<int>> &v, vector<int> &guess)
{
    // cout << "GUESS : ";
    // for(int num : guess) cout << num << " ";
    // cout << "\n";
    int n = guess.size(), k = v.size();
    for(int i = 0 ; i<k ; i++)
    {
        int p = 0;
        for(int j = 1 ; j<n ; j++)
        {
            while(p<n && v[i][j] != guess[p]) p++;
            if(p == n) return false;
        }
    }
    return true;
}

void solve(ll tc_no)
{
    
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(k, vector<int>(n));
    for(vector<int> &temp : v) inp(temp);

    if(k == 1)
    {
        cout << "YES\n";
        return;
    }

    vector<int> t1, t2;
    int n1 = v[0][0], n2 = v[1][0];

    for(int num : v[0])
        if(num!=n1 && num!=n2) t1.pb(num);
    
    for(int num : v[1])
        if(num!=n1 && num!=n2) t2.pb(num);
    
    for(int i = 0 ; i<n-2 ; i++)
        if(t1[i]!=t2[i])
        {
            cout << "NO\n";
            return;
        }
    
    int p1 = 0, p2 = 0;
    for(int i = 0 ; i<n ; i++) if(v[0][i] == n2) p2 = i;
    for(int i = 0 ; i<n ; i++) if(v[1][i] == n1) p1 = i;

    vector<int> guess;
    if(p1 >= p2)
    {
        set<int> seen;
        int k1 = 1, k2 = 1;
        while(k1 < n || k2 < n)
        {
            if(k1<n && v[0][k1] == n2)
            {
                guess.pb(v[0][k1]);
                k1++;
            }
            else if(k2<n && v[1][k2] == n1)
            {
                guess.pb(v[1][k2]);
                k2++;
            }
            else
            {
                guess.pb(v[0][k1]);
                k1++;
                k2++;
                seen.insert(v[0][k1-1]);
            }
        }
        if(verify(v, guess))
        {
            cout << "YES\n";
            return;
        }
    }
    if(p1 <= p2)
    {
        guess = {};
        set<int> seen;
        int k1 = 1, k2 = 1;
        while(k1 < n || k2 < n)
        {
            if(k2<n && v[1][k2] == n1)
            {
                guess.pb(v[1][k2]);
                k2++;
            }
            else if(k<n && v[0][k1] == n2)
            {
                guess.pb(v[0][k1]);
                k1++;
            }
            else
            {
                guess.pb(v[0][k1]);
                k1++;
                k2++;
                seen.insert(v[0][k1-1]);
            }
        }
        if(verify(v, guess))
        {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
    

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