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
// use less_equal for multiple entries

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

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

#define MOD 998244353 // update this based on the provided data

int inv_for_nCr(int a, int m) { // m = MOD
    return a <= 1 ? a : m - (long long)(m/a) * inv_for_nCr(m % a, m) % m;
}

vector<int> factorial;
vector<int> inverse_factorial;
int ans;

void precompute_for_nCr(int x) // call this to get precompute
{
    factorial.resize(x+1);
    inverse_factorial.resize(x+1);

    factorial[0] = 1;
    inverse_factorial[0] = inv_for_nCr(1, MOD);
    for(int i = 1 ; i<=x ; i++)
    {
        factorial[i] = (factorial[i-1]*i) % MOD;
        inverse_factorial[i] = (inverse_factorial[i-1]*inv_for_nCr(i, MOD)) % MOD;
    }
}

int nCr(int n, int r)
{
    if(r > n) return 0LL;
    return (factorial[n] * ((inverse_factorial[r]*inverse_factorial[n-r]) % MOD)) % MOD;
}

void preprocessing()
{
    precompute_for_nCr(200);
}

int recursion(int n, int k, int pos)
{
    if(pos < 0) return k == 0;
    int count = 0;
    int num = 1LL<<pos;
    if(n&num)
    {
        int extra = (((num-1)%MOD) * nCr(pos-1, k)) % MOD;
        if(extra) count = (count + nCr(pos-1, k));
        ans = (ans + extra) % MOD;
    }
    int x = recursion(n, max(k-((n&num)>0), 0LL), pos-1);
    count = (x+count) % MOD;
    ans = (ans + ((n&num)%MOD)*x) % MOD;
    return count;
}

void solve(ll tc_no)
{
    // cout << "Case #" << tc_no << ": ";
    int n, k;
    cin >> n >> k;
    
    ans = 0;

    recursion(n, k, 61);
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

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}