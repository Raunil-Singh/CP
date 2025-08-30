// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long

#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

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
    vector<int> v(n); inp(v);

    if(n == 1)
    {
        cout << "YES\n";
        return;
    }

    vector<int> pos(n);
    for(int i = 0 ; i<n ; i++) pos[v[i]-1] = i;

    // for(int num : pos) cout << num << " ";
    // cout << "#\n";

    if(!((pos[0]==n-1 && pos[1]==0) || (pos[0]==0 && pos[1]==n-1)))
    {
        cout << "NO\n";
        return;
    }

    ordered_set pq;
    pq.insert(n-2);
    map<int, int> counter;
    counter[n-2] = 1;

    ordered_set s;
    s.insert(0);
    s.insert(n-1);
    
    for(int i = 2 ; i<n && (*pq.find_by_order(pq.size()-1))>2 ; i++)
    {
        int tp = (*pq.find_by_order(pq.size()-1));
        int tc = s.order_of_key(pos[i]);
        int l = *s.find_by_order(tc-1);
        int r = *s.find_by_order(tc);
        // cout << l << " " << r << " " << i << " $\n";
        if(min(pos[i]-l-1, r-pos[i]-1) < (tp-1)/2)
        {
            cout << "NO\n";
            return;
        }
        s.insert(pos[i]);
        counter[r-l-1]--;
        if(counter[r-l-1] == 0) pq.erase(r-l-1);
        pq.insert(pos[i]-l-1); 
        pq.insert(r-pos[i]-1);
        counter[pos[i]-l-1]++;
        counter[r-pos[i]-1]++;
    }
    cout << "YES\n";

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
