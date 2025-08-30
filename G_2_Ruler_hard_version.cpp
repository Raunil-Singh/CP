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

int arr[] = {4, 100, 570, 874};
int evaluate(int a, int b, int tc_no)
{
    int ans = arr[tc_no-1];
    int res = 1;
    if(a < ans) res*=a;
    else res*=a+1;
    if(b < ans) res*=b;
    else res*=b+1;
    return res;
}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    
    int l = 0, r = 999;
    while(l+1 < r)
    {
        int x = (r-l)/3;
        int m1 = l + x + 1;
        int m2 = r - x;
        cout << "? " << m1 << " " << m2 << "\n";
        int res; // = evaluate(m1, m2, tc_no);
        cin >> res;
        if(res == m1*m2) l = m2;
        else if(res == m1*(m2+1))
        {
            l = m1;
            r = m2;
        }
        else r = m1;
    }

    cout << "! " << r << "\n";

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