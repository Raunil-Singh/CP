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

bool check(string &s, int ans, int m, int n)
{
    int p1 = 131, p2 = 151;
    int m1 = (1e9) + 7, m2 = (1e9) + 9;
    
    vector<int> pp1(n), pp2(n);
    pp1[0] = 1;
    pp2[0] = 1;
    for(int i = 1 ; i<n ; i++)
    {
        pp1[i] = (pp1[i-1]*p1) % m1;
        pp2[i] = (pp2[i-1]*p2) % m2;
    }
    
    vector<int> h1(n+1), h2(n+1);
    h1[0] = 0;
    h2[0] = 0;
    for(int i = 0 ; i<n ; i++)
    {
        h1[i+1] = (h1[i] + (s[i] - 'a' + 1)*pp1[i]) % m1;
        h2[i+1] = (h2[i] + (s[i] - 'a' + 1)*pp2[i]) % m2;
    }

    int count = 0;
    int init = 0;
    while(init + ans <= n)
    {
        bool f1 = ((h1[init+ans] - h1[init] + m1) % m1 == (h1[ans]*pp1[init]) % m1);
        bool f2 = ((h2[init+ans] - h2[init] + m2) % m2 == (h2[ans]*pp2[init]) % m2);
        // cout << f1 << " " << f2 << " " << init << " @\n";
        if(f1 == true && f2 == true)
        {
            init += ans;
            count++;
        }
        else init++;
    }

    // for(int num : pp1) cout << num << " ";
    // cout << "#\n";
    // for(int num : pp2) cout << num << " ";
    // cout << "#\n";
    // for(int num : h1) cout << num << " ";
    // cout << "#\n";
    // for(int num : h2) cout << num << " ";
    // cout << "#\n";

    // cout << "Count = " << count << " #\n";

    return count >= m;

}

void solve(ll tc_no)
{
    
    ll n, m;
    cin >> n >> m >> m;

    string s;
    cin >> s;

    int l = 0, r = n+1;
    while(l+1<r)
    {
        int mid = l + (r-l)/2;
        if(check(s, mid, m, n)) l = mid;
        else r = mid;
        // cout << l << " " << r << "#\n";
    }
    cout << l << "\n";
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

    signed main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);

        // cout << fixed;
        cout << setprecision(10);

        // code here
        
        return 0;
    }