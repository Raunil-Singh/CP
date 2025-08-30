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

#define MAXN 200001
vector<int> spf(MAXN + 1, 1);

void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}

// a*b , a -> 5
// a, b -> 1
// a*b, a*b -> 3
// a*a, a -> 4
// a*a, a*a -> 2

// 0 -> a
// 1 -> a*a
// 2 -> a*b

void solve(ll tc_no)
{
    
    int n;
    cin >> n;
    vector<int> counts = {0,0,0};
    vector<map<int, int>> m(3);
    for(int i = 0 ; i<n ; i++)
    {
        int num;
        cin >> num;
        int s = spf[num];
        if(num == s)
        {
            m[0][num]++;
            counts[0]++;
        }
        else if(num == s*s) 
        {
            m[1][num]++;
            counts[1]++;
        }
        else if(spf[num/s] == num/s) 
        {
            m[2][num]++;
            counts[2]++;
        }
    }

    int ans = 0;

    // 1
    int temp = 0;
    for(auto [a, b] : m[0])
        temp += b*(counts[0]-b);
    ans += temp/2;

    // cout << ans << "#\n";

    // 2
    temp = 0;
    for(auto [a, b] : m[1])
        temp += b*(b+1)/2;
    ans += temp;
    
    // cout << ans << "#\n";

    // 3
    temp = 0;
    for(auto [a, b] : m[2])
        temp += b*(b+1)/2;
    ans += temp;

    // cout << ans << "#\n";

    // 4
    temp = 0;
    for(auto [a, b] : m[0])
        temp += b*m[1][a*a];
    ans += temp;

    // cout << ans << "#\n";

    // 5
    temp = 0;
    for(auto [a, b] : m[2])
        temp += b*(m[0][spf[a]] + m[0][a/spf[a]]);
    ans += temp;

    cout << ans << "\n";

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    sieve();

    // cout << spf[5] << "##\n";

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}