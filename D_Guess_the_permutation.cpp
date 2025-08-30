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

void s4(vector<int> &v, int p)
{
    cout << "? " << p+1 << " " << p+2 << " " << p+3 << "\n";
    int a; cin >> a;
    cout << "? " << p+2 << " " << p+3 << " " << p+4 << "\n";
    int b; cin >> b;
    cout << "? " << p+1 << " " << p+3 << " " << p+4 << "\n";
    int c; cin >> c;
    cout << "? " << p+1 << " " << p+2 << " " << p+4 << "\n";
    int d; cin >> d;

    int s = (a+b+c+d)/3;
    v[p] = s-b;
    v[p+1] = s-c;
    v[p+2] = s-d;
    v[p+3] = s-a;
}

void sn(vector<int> &v, int p)
{
    cout << "? " << p-1 << " " << p << " " << p+1 << "\n";
    int k; cin >> k;
    v[p] = k - (v[p-1] + v[p-2]);
}

void solve(ll tc_no)
{
    
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int length_done = 0;
    while(n - length_done >= 4)
    {
        s4(v, length_done);
        length_done+=4;
    }

    while(length_done < n)
    {
        sn(v, length_done);
        length_done++;
    }

    cout << "! ";
    for(int num : v) cout << num << " ";
    cout << "\n";
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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