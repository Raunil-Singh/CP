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

void solve2(int &ans, vector<int> &temp, int n)
{
    for(ll j = 1 ; j<n ; j++) temp[j] += temp[j-1];
    for(ll num : temp) cout << num << " ";
    cout << "\n";
    for(ll j = 1 ; j<n ; j++) temp[j] += temp[j-1];
    map<int,int> count;
    map<int, int> m;
    count[0] = 1;
    int prev = 0;
    int prev_score = 0;
    for(ll j = 0 ; j<n ; j++)
    {
        if(temp[j] > prev)
        {
            prev_score += (count.find(temp[j])!=count.end() ? count[temp[j]] : 1);
            m[temp[j]] = prev_score;
        }
        else
        {
            prev_score = m[temp[j]];
            m[temp[j]]++;
        }
        ans -= prev_score; 
        prev = temp[j];
        count[prev]++;
        cout << ans << "," << prev_score << " ";
    }
    cout << "\n";
}

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;
    vector<int> v(n); inp(v);
    int net_ans = 0;
    for(ll i = 1 ; i<=10 ; i++)
    {
        ll ans = n*(n-1)/2 + n;
        vector<int> temp = v;
        for(ll j = 0 ; j<n ; j++)
        {
            if(temp[j] <= i) temp[j] = -1;
            else temp[j] = 1;
        }
        solve2(ans, temp, n);
        temp = v;
        for(ll j = 0 ; j<n ; j++)
        {
            if(temp[j] >= i) temp[j] = -1;
            else temp[j] = 1;
        }
        solve2(ans, temp, n);
        cout << ans << "**\n";
        net_ans += ans;
    }

    cout << net_ans << "\n";
    
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