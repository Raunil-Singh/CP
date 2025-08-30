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


void get_min(vector<int> &b)
{
    int m = b.size();
    vector<int> temp(m);
    int minc = 0;
    for(int i = 0 ; i<m ; i++) if(b[minc] > b[i]) minc = i;
    for(int i = 0 ; i<m ; i++) temp[i] = b[(minc+i)%m];
    b = temp;
}

void solve(ll tc_no)
{
    
    ll n, m;
    cin >> n >> m;
    vector<int> a(n), b(m); inp(a); inp(b);

    get_min(b);

    if(m > 1)
    {
        bool cp = true;

        int pos = 0;
        while(pos < n-m && cp)
        {
            if(b[0] < a[pos]) cp = false;
            if(cp) pos++;
        }

        for(int i = pos ; i<n-m ; i++) a[i] = b[0];

        bool flag = true;
        for(int i = n-m ; i<n && flag && cp ; i++)
            if(a[i] > b[i - n + m]) break;
            else if(a[i] < b[i - n + m]) flag = false;

        if(flag)
        for(int i = n-m ; i<n ; i++) a[i] = b[i - (n-m)];
            
        for(int &num : a) cout << num << " ";
        cout << "\n";
    }
    else
    {
        for(int i = n-m ; i<n ; i++)
        {
            if(a[i] < b[0]) goto NEXT;
        }
        for(int i = n-m ; i<n ; i++) a[i] = b[0];
        NEXT:;
        for(int i = 0 ; i<n-m ;)
        {
            if(a[i] > b[0])
            {
                for(int j = 0 ; j<m ; j++)
                {
                    a[i] = b[0];
                }
                i += m;
                continue;
            }
            i++;
        }
        for(int &num : a) cout << num << " ";
        cout << "\n";
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